#include "BagModel.h"
#include "comp.h"
#include <QString>
bagModel::bagModel(QVector<Bag> *data, QObject *parent)
    : QAbstractTableModel(parent), _bags(data)
{}
bagModel:: bagModel():_bags(new QVector<Bag>())
{}
int bagModel::rowCount([[maybe_unused]] const QModelIndex &parent) const
{
    return _bags->count();
}

int bagModel::columnCount([[maybe_unused]] const QModelIndex &parent) const
{
    return 3;//нащвание товара, секция, цена
}

QVariant bagModel::headerData(int section, Qt::Orientation orientation, int role) const
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
        case 1: return tr("Количетсво");
        case 2: return tr("Секция");
        default: return QVariant();
        }
    }
    else
    {
        return QString("%1").arg(section + 1);//номер секции увеличивается на 1, отображение заголовка
    }
}

QVariant bagModel::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch(index.column())
    {
    case 0: return ((*_bags)[index.row()].Name);
    case 1: return QString("%1").arg((*_bags)[index.row()].Num);
    case 2: return QString("%1").arg((*_bags)[index.row()].Section);

    default: return QVariant();}

    return QVariant();
}

void bagModel::setBags(COMP<Bag>* bags)
{
    beginResetModel();
    _bags->clear();
    for (int i=0; i<bags->GetCount(); i++)
    {
        *_bags<<(bags->at(i));}
    endResetModel();
}
