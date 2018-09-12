#include "value.h"

Value::Value()
{
   m_type = Type::none;
   m_strValue = "";
}

Value::Value(Type type, const QString& strValue)
{
    m_type = type;
    m_strValue = strValue;
}

Value::Value(const QString& textValue)
{
    m_type = Type::text;
    m_strValue = textValue;
}

//*
Value::Value(const char* textValue)
{
    m_type = Type::text;
    m_strValue = textValue;
}
//*/
Value::Value(const std::string& textValue)
{
    m_type = Type::text;
    m_strValue.fromStdString(textValue);
}

Value::Value(int value)
{
    m_type = Type::number;
    m_strValue = QString::number(value);
}

Value::Value(double value)
{
    m_type = Type::number;
    m_strValue = QString::number(value);
}

Value::Value(const QDate& value)
{
    m_type = Type::date;
    m_strValue = value.toString(DATE_FORMAT);
}

Value::Type Value::getType()
{
    return m_type;
}

QString Value::getStrValue()
{
    return m_strValue;
}

double Value::getNumValue()
{
    return m_strValue.toDouble();
}

QDate Value::getDateValue()
{
    return QDate::fromString(DATE_FORMAT);
}

QDomElement Value::toXmlElement()
{
    QDomElement elm;
    elm.setTagName("value");
    elm.setAttribute("type", type2str(m_type));
    elm.setAttribute("strValue", m_strValue);
    return elm;
}

QString Value::type2str(Type type)
{
    switch(type)
    {
    case Type::none:
        return QString("none");
    case Type::text:
        return QString("text");
    case Type::number:
        return QString("number");
    case Type::date:
        return QString("date");
    default:
        return QString("none");
    }
}

Value::Type Value::str2type(QString& str)
{
    if(str == type2str(Type::none))
        return Type::none;
    if(str == type2str(Type::text))
        return Type::text;
    if(str == type2str(Type::number))
        return Type::number;
    if(str == type2str(Type::date))
        return Type::date;
    return Type::none;
}

bool Value::operator==(Value& other)
{
    if(this->m_type != other.getType())
        return false;
    if(this->m_strValue == other.getStrValue())
        return true;
    return false;
}

bool Value::operator!=(Value& other)
{
    return !(*this == other);
}

bool Value::operator<(Value& other)
{
    if(this->m_type != other.getType())
        return false;
    switch(this->m_type)
    {
    case Type::number:
        return (this->getNumValue() < other.getNumValue());
    case Type::date:
        return (this->getDateValue() < other.getDateValue());
    case Type::none:
        return false;
    case Type::text:
        return false;
    default:
        return false;
        break;
    }
}
