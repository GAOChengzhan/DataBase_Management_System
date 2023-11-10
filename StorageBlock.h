//
// Created by Chengzhan Gao on 11/10/23.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_STORAGEBLOCK_H
#define DATABASE_MANAGEMENT_SYSTEM_STORAGEBLOCK_H


#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <variant>
#include <iostream>
#include "Value.h"


namespace ECE141 {

    //a "storage" file comprises fixed-sized blocks (defined below)

    const size_t kPayloadSize = 1012; //area reserved in storage-block for user data...

    enum class BlockType {
        meta_block='T',
        data_block='D',
        entity_block='E',
        free_block='F',
        index_block='I',
        unknown_block='V',
    };

    using NamedBlockNums = std::map<std::string, uint32_t>;

    struct BlockHeader {

        explicit BlockHeader(BlockType aType=BlockType::data_block)
                : type(static_cast<char>(aType)), id(0) {}

        BlockHeader(const BlockHeader &aCopy) {
            *this=aCopy;
        }

        BlockHeader& operator=(const BlockHeader &aCopy) {
            type=aCopy.type;
            id=aCopy.id;
            return *this;
        }

        char      type{};     //char version of block type {[D]ata, [F]ree... }
        uint32_t  id{};       //use this anyway you like
    };

    struct StorageBlock {

        explicit StorageBlock(BlockType aType=BlockType::data_block);

        StorageBlock(const StorageBlock &aCopy);
        StorageBlock& operator=(const StorageBlock &aCopy);

        StorageBlock& store(std::ostream &aStream);

        //we use attributes[0] as table name...
        BlockHeader   header;
        char          data[kPayloadSize]{};
    };


//  class BlockVisitor {
//  public:
//      BlockVisitor(Schema& curSchema, Filters& filters, vector<string>& properties, RowCollection& rowCollection) :
//              schema(curSchema), filters(filters), properties(properties), rowCollection(rowCollection) {};
//
//      StatusResult operator()(Storage& storage, uint32_t blockNum, StorageBlock& block);
//
//  protected:
//      Schema& schema;
//      Filters& filters;
//      vector<string>& properties;
//      RowCollection& rowCollection;
//  };
}

#endif //DATABASE_MANAGEMENT_SYSTEM_STORAGEBLOCK_H
