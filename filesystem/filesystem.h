/* Copyright 2013, 2015 Robert Schroll
 * Copyright 2019 Emanuele Sorce
 *
 * This file is part of Beru and is distributed under the terms of
 * the GPL. See the file COPYING for full details.
 */

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QStringList>
#include <QString>
#include <QProcess>

class FileSystem : public QObject
{
    Q_OBJECT

public:
    // Filesystem
    Q_INVOKABLE int exists(const QString &filename);
    Q_INVOKABLE QString canonicalFilePath(const QString &filename);
    Q_INVOKABLE bool makeDir(const QString &path);
    Q_INVOKABLE QString homePath() const;
    Q_INVOKABLE bool readableHome();
    Q_INVOKABLE QString getDataDir(const QString &subDir);
    Q_INVOKABLE QStringList listDir(const QString &dirname, const QStringList &filters);
    Q_INVOKABLE QString fileType(const QString &filename);
    Q_INVOKABLE bool remove(const QString &filename);

   // Bash interface
   Q_INVOKABLE unsigned int exec(const QString& cmd) const;
   Q_INVOKABLE bool execb(const QString& cmd) const;
};

#endif // FILESYSTEM_H
