//
// Created by Chengzhan Gao on 11/9/23.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_ROW_H
#define DATABASE_MANAGEMENT_SYSTEM_ROW_H

#include <cstdio>
#include <string>
#include <utility>
#include <variant>
#include <vector>
#include <algorithm>
#include "Storage.h"

namespace ECE141 {
    class Schema;

    class Row : public Storable {
    public:

        Row(int32_t blockNum = 0);
        Row(const Row &aRow);
        Row(KeyValues& keyValues, uint32_t blockNum);
        ~Row();
        Row& operator=(const Row &aRow);
        bool operator==(Row &aCopy) const;

        KeyValues copyData() const {return data;}
        KeyValues& getData() {return data;}



        void setBlockNum(uint32_t blockNum);

        uint32_t getBlockNum();

        void insert(KeyValue pair) {data.insert(pair);}

        void addKeyValue(string key, ValueType valueType) { data[key] = valueType; }

        virtual StatusResult  encode(std::ostringstream &aWriter) const;

        static StatusResult decode(Row& row , std::string str);
        //STUDENT: What other methods do you require?
        static Value getData(string str);
        static vector<string> split(string str,string pattern);

        ValueType getDataFromKeyValues(string str);

    protected:
        KeyValues data;  //you're free to change this if you like...
        int32_t blockNum;
    };



    class RowCollection {
    public:
        RowCollection() : rowList() {} ;
        RowCollection(const RowCollection &aCopy) : rowList(aCopy.rowList) {}
        ~RowCollection();

        vector<Row*>    getRows();
        RowCollection&  addRow(Row* aRow);
        RowCollection&  order(Schema& aSchema, string& orderBy);

        RowCollection&  remainLimitPart(int limit);

        StatusResult    leftJoin(RowCollection rc1, RowCollection rc2, vector<string> selectList1, vector<string> selectList2, string attr1, string attr2);

        StatusResult    rightJoin(RowCollection rc1, RowCollection rc2, vector<string> selectList1, vector<string> selectList2, string attr1, string attr2);

        StatusResult    innerJoin(RowCollection rc1, RowCollection rc2, vector<string> selectList1, vector<string> selectList2, string attr1, string attr2);


    protected:
        vector<Row*> rowList;
    };

}

#endif //DATABASE_MANAGEMENT_SYSTEM_ROW_H
