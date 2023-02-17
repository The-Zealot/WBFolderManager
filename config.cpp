#include "config.h"

Config::Config()
{

}

bool Config::readJson(QString &json)
{
    QFile config(json);
    if (config.open(QIODevice::ReadOnly))
    {
        QJsonObject jObject = QJsonDocument::fromJson(config.readAll()).object();

        _configStruct.startDir        = jObject["startDir"].toString();
        _configStruct.defectDir       = jObject["defectDir"].toString();
        _configStruct.discDir         = jObject["discrepancyDir"].toString();
        _configStruct.overDir         = jObject["overageDir"].toString();
        _configStruct.policy          = (MkdirPolicy)jObject["mkdirPolicy"].toInteger();
        _configStruct.copyMovePhoto   = jObject["copyMovePhoto"].toBool();

        config.close();
        return true;
    }

    return false;
}

bool Config::writeJson(QString &json, QJsonObject& jObject)
{
    QJsonDocument jDoc(jObject);
    QFile file(json);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(jDoc.toJson());
        file.close();
        return true;
    }

    return false;
}

ConfigStruct Config::getConfigStruct()
{
    return _configStruct;
}
