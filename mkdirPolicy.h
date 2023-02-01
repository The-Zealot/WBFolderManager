#ifndef MKDIRPOLICY_H
#define MKDIRPOLICY_H

enum MkdirPolicy
{
    Ignore = 0,
    Ask = 1,
    Block = 2
};

enum PrefixType
{
    None = 0,
    DirName = 1,
    Date = 3
};

#endif // MKDIRPOLICY_H
