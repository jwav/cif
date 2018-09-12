#ifndef ERROR_H
#define ERROR_H

#include <QString>
#include <QTime>

//TODO : turn into singleton
class Error
{
public:
    static const size_t MAX_TEXT_SIZE = 1024;

    Error();
    Error(QString name, const char* fmt, ...);
    Error(QString name, QString text);
    //Error(Error& error);

    bool isNone();
    QString getName();
    QString toString();

    static void add(Error err);
    static Error get(uint index=0);
    static void rem(uint index=0);
    static uint nbErrors();

private:
    QString m_name;
    QString m_text;
    static std::vector<Error> m_errors;
};

/*
class Errors
{
public:
    Errors* getInstance();


    void add(Error err);
    Error get(uint index=0);
    void rem(uint index=0);
    uint nbErrors();
private:
    Errors();
    static Errors* m_singleInstance;
    std::vector<Error> m_errors;
};
//*/
#endif // ERROR_H
