//
// Created by Chengzhan Gao on 11/10/23.
//

#include "StorageBlock.h"
#include <cstring>

namespace ECE141 {

    StorageBlock::StorageBlock(BlockType aType) : header(aType) {
        memset(data,0,sizeof(data));
    }

    StorageBlock::StorageBlock(const StorageBlock &aCopy) : header(aCopy.header) {
        std::memcpy(reinterpret_cast<void*>(data), &aCopy.data, kPayloadSize);
    }

    StorageBlock& StorageBlock::operator=(const StorageBlock &aCopy) {
        header=aCopy.header;
        std::memcpy(reinterpret_cast<void*>(data), &aCopy.data, kPayloadSize);
        return *this;
    }

    //USE: save the given stream in this block data area.
    StorageBlock& StorageBlock::store(std::ostream &aStream) {
        return *this;
    }

}