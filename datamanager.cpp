#include "datamanager.h"
#include <QDebug>
#include <QDir>
#include "constants.h"



DataManager::DataManager()
{

}

void DataManager::save(float* weights)
{
    QJsonArray array;
    qDebug() << "SAVING";
    for(int i = 0; i < CELL_COUNT; ++i){
        qDebug() << weights[i] << " weight";
        array.insert(i, QJsonValue(weights[i]));
    }

    qDebug() << "SAVING END";

    auto dirPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    auto filePath = dirPath + QDir::separator() + SAVE_FILE_NAME;
    if(!QDir().exists(dirPath)){
        QDir().mkpath(dirPath);
    }
    QJsonDocument doc(array);
    QFile jsonFile(filePath);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());

}

float* DataManager::read()
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+ QDir::separator() + SAVE_FILE_NAME;
    qDebug() << path;
    float *weights = new float[CELL_COUNT];
    QFile jsonFile(path);
    if(!jsonFile.open(QFile::ReadOnly))
        return NULL;
    QJsonDocument doc = QJsonDocument().fromJson(jsonFile.readAll());
    QJsonArray array = doc.array();
    int i = 0;

    foreach (const QJsonValue &v, array){
        weights[i] = v.toDouble();
        ++i;
    }

    return weights;
}



