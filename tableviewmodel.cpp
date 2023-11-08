#include "tableviewmodel.h"
#include <qdebug.h>
#include <QElapsedTimer>

TableViewModel::TableViewModel(QObject *parent)
{

}

TableViewModel::~TableViewModel()
{

}

int TableViewModel::rowCount(const QModelIndex &parent) const
{
    return modelData.count();
}

int TableViewModel::columnCount(const QModelIndex &parent) const
{
    return headeList.size();
}

QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section < headeList.size())
        {
            return headeList[section];
        }
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool TableViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return 0;
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row=index.row();
        switch(index.column())
        {
        case 0: modelData[row].id=value.toString();break;
        case 1:modelData[row].name=value.toString();break;
        case 2:modelData[row].one=value.toString();break;
        case 3:modelData[row].two=value.toString();break;
        case 4:modelData[row].three=value.toString();break;
        case 5:modelData[row].four=value.toString();break;
        case 6:modelData[row].five=value.toString();break;
        case 7:modelData[row].six=value.toString();break;

        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}


bool TableViewModel::insertRows(int row, int count,const QModelIndex &parent)
{
    if(row<0||count<1||row>rowCount())
           return false;
       //需要将操作放到beginInsertRows和endInsertRows两个函数调用之间
       beginInsertRows(parent, row, row + count - 1);
       for(int i=row;i<row+count;i++)
       {
           //在接口对应行插入空数据
           ModelItem elem;
           modelData.insert(i, elem);
       }
       endInsertRows();
    //       return true;
}

bool TableViewModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row<0||count<1||row+count>rowCount())
        return false;
    //需要将操作放到beginRemoveRows和endRemoveRows两个函数调用之间

    beginRemoveRows(parent, row, row + count - 1);

    if(m_DeleteList.size()!=0)
    {
        for(int i=0;i<m_DeleteList.size();i++)
        {
            modelData.removeAt(m_DeleteList[i]);
        }
    }

//    for(int i=row+count-1;i>=row;i--)
//    {
//        //移除该行数据
//        modelData.removeAt(i);
//    }
    m_DeleteList.clear();
    endRemoveRows();

    return true;
}

void TableViewModel::SetDeleteList(QList<int> i_List)
{
    m_DeleteList=i_List;
}



QVariant TableViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row=index.row();
        switch(index.column())
        {
        case 0: return modelData.at(row).id;
        case 1:return modelData.at(row).name;
        case 2:return modelData.at(row).one;
        case 3:return modelData.at(row).two;
        case 4:return modelData.at(row).three;
        case 5:return modelData.at(row).four;
        case 6:return modelData.at(row).five;
        case 7:return modelData.at(row).six;
        }
    }
    return QVariant();
}

void TableViewModel::SetHeadData(QStringList i_list)
{
    headeList=i_list;
}

void TableViewModel::SetModelData(QList<ModelItem> model)
{
    modelData=model;
}







