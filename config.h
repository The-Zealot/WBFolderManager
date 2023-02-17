#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

#include "MkdirPolicy.h"

///////////// А нахуя? Чего я этим добился? /////////////

struct ConfigStruct
{
    QString startDir;
    QString defectDir;
    QString discDir;
    QString overDir;
    MkdirPolicy policy;
    bool copyMovePhoto;
};

class Config
{
public:
    Config();

    bool readJson(QString &json);
    bool writeJson(QString &json, QJsonObject& jObject);

    ConfigStruct getConfigStruct();

private:
    ConfigStruct _configStruct;
};

#endif // CONFIG_H
