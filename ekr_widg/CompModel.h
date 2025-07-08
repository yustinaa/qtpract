#ifndef COMPMODEL_H
#define COMPMODEL_H
#include <QAbstractTableModel>
#include <comp.h>
class compModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    compModel(QVector<Comp> *comps, QObject *parent = nullptr);
    compModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setComps(COMP<Comp>* comp);
protected:
    QVector<Comp> *_comps;
};
#endif // COMPMODEL_H
