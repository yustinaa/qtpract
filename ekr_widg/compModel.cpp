#include "CompModel.h"
#include "comp.h"
#include <QString>
compModel::compModel(QVector<Comp> *data, QObject *parent)
    : QAbstractTableModel(parent), _comps(data)
{}
compModel:: compModel():_comps(new QVector<Comp>())
{}
int compModel::rowCount([[maybe_unused]] const QModelIndex &parent) const
{
    return _comps->count();
}

int compModel::columnCount([[maybe_unused]] const QModelIndex &parent) const
{
    return 3;//нащвание товара, секция, цена
}

QVariant compModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case 0: return tr("Товар");
        case 1: return tr("Секция");
        case 2: return tr("Цена");
        default: return QVariant();
        }
    }
    else
    {
        return QString("%1").arg(section + 1);//номер секции увеличивается на 1, отображение заголовка
    }
}

QVariant compModel::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch(index.column())
    {
    case 0: return ((*_comps)[index.row()].Name);
    case 1: return QString("%1").arg((*_comps)[index.row()].Section);
    case 2: return QString("%1").arg((*_comps)[index.row()].Price);

    default: return QVariant();}

    return QVariant();
}

void compModel::setComps(COMP<Comp>* comps)
{
    beginResetModel();
    _comps->clear();
    for (int i=0; i<comps->GetCount(); i++)
    {
        *_comps<<(comps->at(i));}
    endResetModel();
}
