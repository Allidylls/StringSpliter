/* string_spliter.cpp */

#include <string>
#include "string_spliter.h"

StringSpliter::StringSpliter(const char* str, const char* delimiters, int empties)
{
	if (str && delimiters) {
		size_t n = strlen(str) + 1;
		char  *p = (char*)malloc(n);
		if (p) {
			this->m_string = (char*)memcpy(p, str, n);
		} else {
			this->m_string = NULL;
		}
	} else {
		this->m_string = NULL;
	}
	this->m_delimiters        = delimiters;
	this->m_current           = NULL;
	this->m_next              = this->m_string;
	this->m_is_ignore_empties = (empties != StringSpliter::EMPTIES_OK);
}

StringSpliter::~StringSpliter()
{
	free(this->m_string);
	this->m_string = NULL;
}

const char* StringSpliter::Next()
{
	if (!this->m_string || !this->m_next) {
		return NULL;
	}

	this->m_current = this->m_next;
	this->m_next = strpbrk(this->m_current, this->m_delimiters);

	if (this->m_next) {
		*(this->m_next) = '\0';
		this->m_next += 1;
		if (this->m_is_ignore_empties) {
			this->m_next += strspn(this->m_next, this->m_delimiters);
			if (!(*(this->m_current))) {
				return this->Next();
			}
		}
	} else if (this->m_is_ignore_empties && !(*(this->m_current))) {
		return NULL;
	}

	return this->m_current;
}
