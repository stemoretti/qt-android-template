#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QColor>
#include <QString>

class QQmlEngine;
class QJSEngine;

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool darkTheme READ darkTheme WRITE setDarkTheme NOTIFY darkThemeChanged)
    Q_PROPERTY(QColor primaryColor READ primaryColor WRITE setPrimaryColor NOTIFY primaryColorChanged)
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)

public:
    virtual ~Settings();

    static Settings *instance();
    static QObject *singletonProvider(QQmlEngine *qmlEngine, QJSEngine *jsEngine);

    void readSettingsFile();
    void writeSettingsFile() const;

    bool darkTheme() const;
    void setDarkTheme(bool darkTheme);

    QColor primaryColor() const;
    void setPrimaryColor(const QColor &primaryColor);

    QColor accentColor() const;
    void setAccentColor(const QColor &accentColor);

    QString language() const;
    void setLanguage(const QString &language);

    Q_INVOKABLE static QStringList translations();

Q_SIGNALS:
    void darkThemeChanged(bool darkTheme);
    void primaryColorChanged(QColor primaryColor);
    void accentColorChanged(QColor accentColor);
    void languageChanged(QString language);

private:
    explicit Settings(QObject *parent = nullptr);
    Q_DISABLE_COPY(Settings)

    QString m_settingsFilePath;

    bool m_darkTheme;
    QColor m_primaryColor;
    QColor m_accentColor;
    QString m_language;
};

#endif // SETTINGS_H
