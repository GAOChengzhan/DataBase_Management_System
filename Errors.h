//
// Created by Chengzhan Gao on 11/9/23.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_ERRORS_H
#define DATABASE_MANAGEMENT_SYSTEM_ERRORS_H

namespace ECE141 {

    enum Errors {
        //parse related...
        keywordExpected=100,
        identifierExpected=110,
        illegalIdentifier=115,
        unknownIdentifier=120,
        unexpectedIdentifier=125,
        joinTypeExpected=130,
        keyExpected=135,
        syntaxError=140,
        unexpectedKeyword=145,
        unexpectedValue=150,
        valueExpected=155,
        operatorExpected=160,
        punctuationExpected=165,
        eofError=199,

        //statement related...
        statementExpected=200,
        noDatabaseSpecified=210,

        //table/DB related...
        tableExists=300,
        unknownTable=310,
        unknownDatabase = 320,
        databaseExists = 330,

        //type related...
        unknownType=400,
        unknownAttribute=405,
        invalidAttribute=410,
        invalidArguments=420,
        keyValueMismatch=430, //# of fieldnames doesn't match values...
        // jhx
        duplicateAttributes = 7001,
        missingAttributes = 7002,

        //storage/io related...
        readError=500,
        writeError=510,
        seekError=520,
        storageFull=530,

        //index related
        indexExists=600,
        unknownIndex=610,

        //command related...
        unknownCommand=3000,
        invalidCommand=3010,

        //general purpose...
        userTerminated = 4998,
        notImplemented = 4999,
        noError=5000,

        // jhx
        decodeError = 7000,
        unkownOperator = 7004,

        unknownError = 10000
    };


    struct StatusResult {
        Errors    code;
        uint32_t  value;

        //constructor inline implementation
        explicit StatusResult(Errors aCode = Errors::noError, uint32_t aValue=0) : code(aCode), value(aValue) {}
        explicit operator bool() const {return Errors::noError==code || Errors::userTerminated==code;}
    };

}

#endif //DATABASE_MANAGEMENT_SYSTEM_ERRORS_H
