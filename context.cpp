#include "context.h"
#include <QtXml>

Context::Context(QString name)
    : m_name(name)
{}

Context::~Context()
{
    uint n = m_items.size();
    for(uint i=0; i < n; i++)
        delete m_items[i];
    m_items.clear();
    /*
    n = m_fields.size();
    for(uint i=0; i < n; i++)
        delete m_fields[i];

    m_fields.clear();
    //*/
}

QString Context::getName()
{
    return m_name;
}

void Context::setName(const QString& name)
{
    m_name = name;
}

uint Context::nbItems()
{
    return m_items.size();
}

bool Context::hasItem(id_t itemId)
{
    return (getItemById(itemId) != nullptr);
}

uint Context::getItemIndex(id_t itemId)
{
    uint n = nbItems();
    for(uint i=0; i < n; i++)
    {
        if(m_items[i]->getId() == itemId)
            return i;
    }
    return INVALID_INDEX;
}

bool Context::addItem(Item* item)
{
    if(item == nullptr)
        return false;

    item->setId(nextItemId());
    item->m_context = this;
    m_items.push_back(item);
    return true;
}

bool Context::deleteItem(id_t itemId)
{
    uint index = getItemIndex(itemId);

    if(index == INVALID_INDEX)
    {
        return false;
    }
    delete m_items[index];
    m_items.erase(m_items.begin() + index);
    return true;
}

id_t Context::nextItemId()
{
    if(nbItems() < 1)
        return 0;
    id_t maxId = m_items.back()->getId();
    return maxId +1;
}

Item* Context::getItemById(id_t itemId)
{
    uint index = getItemIndex(itemId);
    if(index == INVALID_INDEX)
        return nullptr;
    return m_items[index];
}

// suppressed "field" methods
/*
uint Context::nbFields()
{
    return m_fields.size();
}

bool Context::hasField(id_t fieldId)
{
    return (getFieldIndex(fieldId) != INVALID_INDEX);
}

uint Context::getFieldIndex(id_t fieldId)
{
    uint n = nbFields();
    for(uint i=0; i < n; i++)
    {
        if(m_fields[i]->getId() == fieldId)
            return i;
    }
    return INVALID_INDEX;
}

bool Context::addField(Field* field)
{
    if(field == nullptr)
        return false;

    field->setId(nextFieldId());
    m_fields.push_back(field);
    return true;
}

bool Context::deleteField(id_t fieldId)
{
    uint index = getFieldIndex(fieldId);

    if(index == INVALID_INDEX)
    {
        return false;
    }
    delete m_fields[index];
    m_fields.erase(m_fields.begin() + index);
    return true;
}

id_t Context::nextFieldId()
{
    id_t maxId = m_fields.back()->getId();
    return maxId +1;
}

Field* Context::getFieldById(id_t fieldId)
{
    uint index = getFieldIndex(fieldId);
    if(index == INVALID_INDEX)
        return nullptr;
    return m_fields[index];
}
//*/
//TODO: redo all
QDomDocument Context::toXML()
{
    QDomDocument doc;
    //*
    QDomElement root = doc.createElement("context");
    root.setAttribute("name", m_name);

    // for each item...
    uint nbItems = m_items.size();
    for(uint i=0; i < nbItems; i++)
    {
        // build item :
        Item* item = m_items[i];
        QDomElement xItem
                = doc.createElement("item");

        xItem.setAttribute("id", item->getId());
        xItem.setAttribute("name", item->getName());
        std::vector<QString> tags = item->getTags();
        uint nbTags = tags.size();

        // for each tag...
        for(uint j=0; j < nbTags; j++)
        {
            //xItem.setAttribute("tag", tags[j]);
            QDomElement xTag = doc.createElement("tag");
            xTag.setAttribute("text", tags[j]);
            xItem.appendChild(xTag);
        }

        // build item's field ids list
        std::vector<Field*> fields = item->getFields();

        uint nbFields = fields.size();
        // for each field...
        for(uint j=0; j < nbFields; j++)
        {
            Field* field = fields[j];
            QDomElement xField = doc.createElement("field");
            xField.setAttribute("id", field->getId());
            xField.setAttribute("name", field->getName());

            xItem.appendChild(xField);
        }
        // add item to document
        root.appendChild(xItem);
    }

    //*/
    doc.appendChild(root);
    return doc;
}

bool Context::buildFromXML(QDomDocument &doc)
{
    //TODO
    return true;
}
