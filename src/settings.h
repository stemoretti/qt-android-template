#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QColor>
#include <QString>

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool darkTheme READ darkTheme WRITE setDarkTheme NOTIFY darkThemeChanged)
    Q_PROPERTY(QColor primaryColor READ primaryColor WRITE setPrimaryColor NOTIFY primaryColorChanged)
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)
    Q_PROPERTY(QString region READ region WRITE setRegion NOTIFY regionChanged)

public:
    virtual ~Settings();

    static Settings &instance();

    void readSettingsFile();

    //{{{ Properties getters declarations

    bool darkTheme() const;
    QColor primaryColor() const;
    QColor accentColor() const;
    QString language() const;
    QString region() const;

    //}}} Properties getters declarations

signals:
    //{{{ Properties signals

    void darkThemeChanged(bool darkTheme);
    void primaryColorChanged(QColor primaryColor);
    void accentColorChanged(QColor accentColor);
    void languageChanged(QString language);
    void regionChanged(const QString &region);

    //}}} Properties signals

public slots:
    void writeSettingsFile() const;

    //{{{ Properties setters declarations

    void setDarkTheme(bool darkTheme);
    void setPrimaryColor(const QColor &primaryColor);
    void setAccentColor(const QColor &accentColor);
    void setLanguage(const QString &language);
    void setRegion(const QString &region);

    //}}} Properties setters declarations

private:
    explicit Settings(QObject *parent = nullptr);
    Q_DISABLE_COPY(Settings)

    QString m_settingsFilePath;

    //{{{ Properties declarations

    bool m_darkTheme;
    QColor m_primaryColor;
    QColor m_accentColor;
    QString m_language;
    QString m_region;

    //}}} Properties declarations
};

#endif // SETTINGS_H
