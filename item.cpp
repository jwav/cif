#include "item.h"

Item::Item(QString& name, id_t id, Context* context, id_t parentId)
    : m_context(context),
      m_id(id),
      m_name(name),
      m_parentId(parentId)
{
}

bool Item::isValid()
{
    return (m_id != INVALID_ID);
}

id_t Item::getId()
{
    return m_id;
}

void Item::setId(id_t id)
{
    m_id = id;
}

QString Item::getName()
{
    return m_name;
}

void Item::setName(QString& name)
{
    m_name = name;
}

id_t Item::getParentId()
{
    return m_parentId;
}

bool Item::hasParent()
{
    return (m_parentId != INVALID_ID);
}

std::vector<Item*> Item::getChildren()
{
    return m_children;
}

bool Item::hasChild(id_t itemId)
{
    for(uint i=0; i < m_children.size(); i++)
    {
        if(m_children[i]->getId() == itemId)
            return true;
    }
    return false;
}

bool Item::addField(Field* field)
{
    if(field == nullptr)
        return false;
    // if already exists
    QString name = field->getName();
    if(hasField(name))
        return false;
    m_fields.push_back(field);
    return true;
}

bool Item::remField(QString& name)
{
    uint index = getFieldIndex(name);

    // TODO : push error
    if(index == UINT_MAX)
        return false;

    delete m_fields[index];
    m_fields.erase(m_fields.begin()+ index);
    return true;
}

uint Item::getFieldIndex(QString& name)
{
    for(uint i=0; i < m_fields.size(); i++)
    {
        Field* field = m_fields[i];
        if(field == nullptr)
            break;
        if(name == field->getName())
            return i;
    }
    return INVALID_INDEX;
}

bool Item::hasField(QString& name)
{
    return (getFieldIndex(name) < nbFields());
}

Field* Item::getField(QString &fieldName)
{
    uint index = getFieldIndex(fieldName);
    if(index >= nbFields())
        return nullptr;

    return m_fields[index];
}

Field* Item::getField(uint index)
{
    if(index >= nbFields())
        return nullptr;

    return m_fields[index];
}

std::vector<Field*> Item::getFields()
{
    return m_fields;
}

uint Item::nbFields()
{
    return m_fields.size();
}

void Item::addTag(QString& tag)
{
    if(hasTag(tag))
        return;
    m_tags.push_back(tag);
}

void Item::remTag(QString& tag)
{
    uint index = getTagIndex(tag);
    if(index == UINT_MAX)
        return;

    m_tags.erase(m_tags.begin() +index);
}

bool Item::hasTag(QString &tag)
{
    return (getTagIndex(tag) != UINT_MAX);
}

uint Item::getTagIndex(QString& tag)
{
    for(uint i=0; i < m_tags.size(); i++)
    {
        if(m_tags[i] == tag)
            return i;
    }
    return UINT_MAX;
}

std::vector<QString> Item::getTags()
{
    return m_tags;
}

QDomElement Item::toXmlElement()
{
    QDomElement elm;
    elm.setTagName("item");
    elm.setAttribute("id", m_id);
    elm.setAttribute("name", m_name);
    elm.setAttribute("parentId", m_parentId);
    for(uint i=0; i < m_tags.size(); i++)
    {
        QDomElement elmTags;
        elmTags.setTagName("tag");
        elmTags.setAttribute("text", m_tags[i]);
        elm.appendChild(static_cast<QDomNode>(elmTags));
    }
    for(uint i=0; i < m_fields.size(); i++)
    {
        Field* field = m_fields[i];
        if(field == nullptr)
            continue;
        QDomElement elmField = field->toXmlElement();
        elm.appendChild(elmField);
    }
    for(uint i=0; i < m_children.size(); i++)
    {
        Item* child = m_children[i];
        if(child == nullptr)
            continue;
        QDomElement elmChild = child->toXmlElement();
        elm.appendChild(elmChild);
    }
    return elm;
}
