// This is the source code of AyuGram for Desktop.
//
// We do not and cannot prevent the use of our code,
// but be respectful and credit the original author.
//
// Copyright @Radolyn, 2026
#pragma once

#include <QtCore/QJsonDocument>
#include <QtXml/QDomDocument>

class AyuLanguage : public QObject
{
	Q_OBJECT
	Q_DISABLE_COPY(AyuLanguage)

public:
	static AyuLanguage *currentInstance();
	static void init();
	static AyuLanguage *instance;

	void applyLanguageJson(QJsonDocument doc);

private:
	AyuLanguage();
	~AyuLanguage() override = default;

	void loadCachedLanguage();
	[[nodiscard]] QString getCacheDir() const;
	[[nodiscard]] QString getCachePath(const QString &langId) const;

};
