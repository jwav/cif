#ifndef CONTEXT_H
#define CONTEXT_H

#include <QString>
#include <vector>
#include <QtXml>

#include "item.h"

//TODO : add friendship towards Item and Field ?

class Context
{
public:
    Context(QString name);
    ~Context();
    QString getName();
    void setName(const QString& name);
    uint nbItems();
    bool hasItem(id_t itemId);
    uint getItemIndex(id_t itemId);
    bool addItem(Item* item);
    bool deleteItem(id_t itemId);
    id_t nextItemId();
    Item* getItemById(id_t itemId);

    /*
    uint nbFields();
    bool hasField(id_t fieldId);
    uint getFieldIndex(id_t fieldId);
    bool addField(Field* field);
    bool deleteField(id_t fieldId);
    id_t nextFieldId();
    Field* getFieldById(id_t fieldId);
    //*/

    QDomDocument toXML();
    bool buildFromXML(QDomDocument &doc);

private:
    QString m_name;
    std::vector<Item*> m_items;
    //std::vector<Field*> m_fields;
};

#endif // CONTEXT_H
