//
// Created by Chengzhan Gao on 11/9/23.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_VALUE_H
#define DATABASE_MANAGEMENT_SYSTEM_VALUE_H

#include <utility>
#include <variant>
#include <optional>
#include <string>
#include <map>
#include <cstdint>
#include <unordered_map>
#include "Errors.h"

using namespace std;

namespace ECE141 {

    struct Storable {
        virtual StatusResult  encode(std::ostringstream &aWriter) const =0;
//     virtual StatusResult  decode(std::istream &aReader)=0;
    };

    enum class DataType {
        no_type='N', bool_type='B', datetime_type='D', float_type='F', int_type='I', varchar_type='V',
    };

    using Value = std::variant<uint32_t, float, bool, std::string>;

    class ValueType {
    public:
        ValueType(){}
        ValueType(Value aValue , DataType aType) : value(std::move(aValue)) , type(aType) {}
        ValueType(uint32_t aValue , DataType aType) : value(aValue) , type(aType) {}
        ValueType(float aValue , DataType aType) : value(aValue) , type(aType) {}
        ValueType(bool aValue , DataType aType) : value(aValue) , type(aType) {}
        ValueType(std::string aValue , DataType aType) : value(aValue) , type(aType) {}

        ValueType(const ValueType& another) {
            this->value = another.value;
            this->type = another.type;
        }

        explicit operator string();

        bool operator<(const ValueType& valueType) const;

        ValueType& operator=(const ValueType& valueType);

        bool operator==(const ValueType& valueType) const;


        Value value;
        DataType type;
    };

    using KeyValues = std::map<const std::string, ValueType>;

    using KeyValue = std::pair<const std::string, ValueType>;

    static std::unordered_map<char, std::string> BlockTypeStrings{
            {'T', "Meta"},
            {'D', "Data"},
            {'E', "Entity"},
            {'F', "Free"},
            {'I', "Index"},
            {'V', "Unknow"},
    };

    static std::unordered_map<DataType, string> DataTypeToStr{
            {DataType::varchar_type, "V"},
            {DataType::int_type, "I"},
            {DataType::float_type, "F"},
            {DataType::bool_type, "B"},
            {DataType::datetime_type, "D"},
            {DataType::no_type, "N"}
    };

    static std::unordered_map<string, DataType> StrToDataType{
            {"V", DataType::varchar_type},
            {"I", DataType::int_type},
            {"F", DataType::float_type},
            {"B", DataType::bool_type},
            {"D", DataType::datetime_type},
            {"N", DataType::no_type}
    };
}

#endif  //DATABASE_MANAGEMENT_SYSTEM_VALUE_H
