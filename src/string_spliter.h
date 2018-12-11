/* string_spliter.h */

#pragma once
#ifndef STRING_SPLITER_H
#define STRING_SPLITER_H

class StringSpliter {
public:
    enum {EMPTIES_OK = 0, NO_EMPTIES};

public:
    StringSpliter(const char* str, const char* delimiters, int empties = StringSpliter::EMPTIES_OK);
    ~StringSpliter();
    const char* Next();

private:
    char*       m_string;
    const char* m_delimiters;
    char*       m_current;
    char*       m_next;
    bool        m_is_ignore_empties;
};

#endif
