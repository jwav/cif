#ifndef FIELD_H
#define FIELD_H

#include <QString>

#include "value.h"
#include "utils.h"

class Field
{
public:
    Field(id_t id, QString& name, Value& value);

    id_t getId();
    QString getName();
    Value getValue();
    Value* getValuePtr();
    void setId(id_t id);
    void setName(QString& name);
    void setValue(Value& value);

    QDomElement toXmlElement();
private:
    id_t m_id;
    QString m_name;
    Value m_value;
};

#endif // FIELD_H
