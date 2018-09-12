#include "error.h"
#include <stdarg.h>

std::vector<Error> Error::m_errors;

Error::Error()
{
    m_name = "";
    m_text = "";
}

Error::Error(QString name, const char* fmt, ...)
{
    m_name = name;

    va_list args;
    va_start(args, fmt);
    char buffer[MAX_TEXT_SIZE];
    vsprintf(buffer, fmt, args);
    va_end(args);

    m_text = QString(buffer);
}

Error::Error(QString name, QString text)
    : m_name(name), m_text(text)
{}

bool Error::isNone()
{
    return (m_name == "" && m_text == "");
}

QString Error::getName()
{
    return m_name;
}

QString Error::toString()
{
    return m_name + ": " + m_text;
}

void Error::add(Error err)
{
    m_errors.push_back(err);
}

Error Error::get(uint index)
{
    Error err;
    if(index > nbErrors())
        return err;
    return m_errors[index];
}

void Error::rem(uint index)
{
    if(index > nbErrors())
        return;
    m_errors.erase(m_errors.begin()+index);
}

uint Error::nbErrors()
{
    return m_errors.size();
}

/// ERRORS
/*
Errors* Errors::m_singleInstance = nullptr;

Errors::Errors()
{}

Errors* Errors::getInstance()
{
    if(m_singleInstance == nullptr)
        m_singleInstance = new Errors();
    return m_singleInstance;
}

void Errors::add(Error err)
{
    m_errors.push_back(err);
}

Error Errors::get(uint index)
{
    Error err;
    if(index > nbErrors())
        return err;
    return m_errors[index];
}

void Errors::rem(uint index)
{
    if(index > nbErrors())
        return;
    m_errors.erase(m_errors.begin()+index);
}

uint Errors::nbErrors()
{
    return m_errors.size();
}
//*/
