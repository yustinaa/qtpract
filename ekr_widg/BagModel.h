#ifndef BAGMODEL_H
#define BAGMODEL_H
#include <QAbstractTableModel>
#include <comp.h>
class bagModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    bagModel(QVector<Bag> *bags, QObject *parent = nullptr);
    bagModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setBags(COMP<Bag>* students);
protected:
    QVector<Bag> *_bags;
};
#endif // BAGMODEL_H
