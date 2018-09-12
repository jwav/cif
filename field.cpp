#include "field.h"

Field::Field(id_t id, QString& name, Value& value)
{
    m_id = id;
    m_name = name;
    m_value = value;
}

id_t Field::getId()
{
    return m_id;
}

QString Field::getName()
{
    return m_name;
}

Value Field::getValue()
{
    return m_value;
}

Value* Field::getValuePtr()
{
    return &m_value;
}

void Field::setId(id_t id)
{
    m_id = id;
}

void Field::setName(QString &name)
{
    m_name = name;
}

void Field::setValue(Value &value)
{
    m_value = value;
}

QDomElement Field::toXmlElement()
{
    QDomElement elm;
    elm.setTagName("field");
    elm.setAttribute("id", m_id);
    elm.setAttribute("name", m_name);
    QDomElement elmValue = m_value.toXmlElement();
    elm.appendChild(elmValue);
    return elm;
}
