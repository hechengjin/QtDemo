#ifndef DATADEFINE
#define DATADEFINE
#include "dataType.h"

#define DEFAULT_VALUE_ZERO    0
//#define NOT_SET_VALUE    4294967295 //-1 99999999  4294967295

struct MailFolderInfo
{
    MailFolderInfo()
    : id(DEFAULT_VALUE_ZERO)
    , parentId(DEFAULT_VALUE_ZERO)
    , numLocalMessages(DEFAULT_VALUE_ZERO)
    , numServerMessages(DEFAULT_VALUE_ZERO)
    , numUnread(DEFAULT_VALUE_ZERO)
    , sizeDisk(DEFAULT_VALUE_ZERO)
    , flags(DEFAULT_VALUE_ZERO)
    , serverID(DEFAULT_VALUE_ZERO)
    , sortValue(DEFAULT_VALUE_ZERO)
    , priority(DEFAULT_VALUE_ZERO)
    , syncCount(DEFAULT_VALUE_ZERO)
    {
    }

    uint32_t id;
    QString showName;
    uint32_t parentId;
    QString realName;
    QString pathName;
    uint32_t numLocalMessages;
    uint32_t numServerMessages;
    uint32_t numUnread;
    uint32_t sizeDisk;
    uint32_t flags;
    uint32_t serverID;
    uint32_t sortValue;
    uint32_t priority;
    uint32_t syncCount;
};

#endif // DATADEFINE

