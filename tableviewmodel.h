#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QWidget>
#include <QAbstractTableModel>

struct ModelItem {
   QString id;
   QString name;
   QString one;
   QString two;
   QString three;
   QString four;
   QString five;
   QString six;
};


class TableViewModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableViewModel(QObject *parent = nullptr);
    ~TableViewModel();

    bool insertRows(int row, int count,const QModelIndex &parent) override;

   int rowCount(const QModelIndex &parent = QModelIndex())const override;
   int columnCount(const QModelIndex &parent = QModelIndex())const override;
   QVariant data(const QModelIndex &index, int role = Qt::DisplayRole)const override;
   QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
   bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
   //bool insertRows(int row, int count,const QModelIndex &parent = QModelIndex());
   virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

   void SetDeleteList(QList<int> i_List);

    void SetHeadData(QStringList i_list);

    void SetModelData(QList<ModelItem> model);

signals:

private:
    QList<ModelItem> modelData;
    QStringList headeList;
    QList<int> m_DeleteList;

};


#endif // TABLEVIEWMODEL_H
