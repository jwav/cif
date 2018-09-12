#ifndef VALUE_H
#define VALUE_H

#include <QString>
#include <QDate>
#include <QtXml>

#define DATE_FORMAT "yyyy-MM-dd"

class Value
{
public:
    enum class Type {none, text, number, date};

    Value();
    Value(Type type, const QString& strValue);
    Value(const QString& textValue);
    Value(const char* textValue);
    Value(const std::string& textValue);

    Value(int value);
    Value(double value);
    Value(const QDate& value);

    Type getType();

    QString getStrValue();
    double getNumValue();
    QDate getDateValue();
    QDomElement toXmlElement();
    static QString type2str(Type type);
    static Type str2type(QString& str);

    bool operator==(Value& other);
    bool operator!=(Value& other);
    bool operator<(Value& other);
private:
    Type m_type;
    QString m_strValue;
};

#endif // VALUE_H
