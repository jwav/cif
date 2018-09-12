#include "mainwindow.h"
#include <QApplication>

#include "context.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();

    QFile file("c:\\Users\\Vee\\Desktop\\out.xml");
    if(!file.open(QFile::WriteOnly | QFile::Truncate))
        return a.exec();

    cout << "a" << endl;
    Context context("fooContext");
    cout << "b" << endl;
    QString itemName("item1");
    cout << "c" << endl;
    Item* item1 = new Item(itemName);
    cout << "d" << endl;

    Value fieldValue(QString("hello"));
    QString fieldName("field1");
    Field* field = new Field(0, fieldName, fieldValue);
    item1->addField(field);

    cout << "context.nbItems() = " << context.nbItems() << endl;
    context.addItem(item1);
    cout << "context.nbItems() = " << context.nbItems() << endl;


    QDomDocument doc = context.toXML();
    /*
    QTextStream ts(stdout);
    cout << "DOC:";
    cout << doc.toString().toStdString() << endl;
    cout << "VALUE:";
    cout << "cout: " << fieldValue.toXmlElement().tagName().toStdString() << endl;
    ts << "ts: " << fieldValue.toXmlElement() << endl;

    QDomElement elm;
    elm.setTagName("element");
    elm.setAttribute("foo", "bar");
    cout << "cout elm: " << elm.tagName().toStdString() << endl;
    ts << "ts elm: " << elm << endl;
    doc.appendChild(elm);

    QDomElement crElm = doc.createElement("createdElement");
    crElm.setAttribute("foo", "bar");
    doc.appendChild(crElm);
    ts << "ts crelm: " << crElm << endl;
    //*/
    /*
    QDomElement root = doc.createElement("root");
    root.setAttribute("name", "root");
    QDomElement node1 = doc.createElement("node");
    node1.setAttribute("name", "node1");
    QDomElement node2 = doc.createElement("node");
    node2.setAttribute("name", "node2");
    QDomElement tag21 = doc.createElement("tag");
    tag21.setAttribute("text", "blabla");
    node2.appendChild(tag21);

    root.appendChild(node1);
    root.appendChild(node2);
    doc.appendChild(root);

    //*/
    QTextStream stream(&file);
    doc.save(stream, 4);
    /*
    Context context("fooContext");
    context.addItem(new Item(0, "item0"));
    context.addItem(new Item(1, "item1"));
    context.addItem(new Item(0, "item00", 0));

    context.addField(new Field(0, "field0", Value("foo")));
    context.addField(new Field(1, "field1", Value("bar")));
    context.addField(new Field(2, "field2", Value(42.0)));

    context.getItemById(0)->addField(0);
    context.getItemById(1)->addField(1);
    context.getItemById(2)->addField(2);
    //*/

    cout << "FINISHED" << endl;
    return 0;//a.exec();
}
