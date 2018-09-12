#ifndef ITEM_H
#define ITEM_H

#include <QString>

#include "field.h"

class Context;

class Item
{
    friend class Context;
public:
    Item(QString& name, id_t id=INVALID_ID, Context* context=nullptr, id_t parentId=INVALID_ID);

    bool isValid();
    id_t getId();
    void setId(id_t id);
    QString getName();
    void setName(QString& name);

    id_t getParentId();
    bool hasParent();

    std::vector<Item*> getChildren();
    bool hasChild(id_t itemId);

    bool addField(Field* field);
    bool remField(QString& name);
    uint getFieldIndex(QString& name);
    bool hasField(QString& name);
    Field* getField(QString& fieldName);
    Field* getField(uint index);
    std::vector<Field*> getFields();
    uint nbFields();

    void addTag(QString& tag);
    void remTag(QString& tag);
    bool hasTag(QString& tag);
    uint getTagIndex(QString& tag);
    std::vector<QString> getTags();

    QDomElement toXmlElement();
private:
    Context* m_context;
    id_t m_id;
    QString m_name;
    id_t m_parentId;
    std::vector<Field*> m_fields;
    std::vector<Item*> m_children;
    std::vector<QString> m_tags;
};

#endif // ITEM_H
