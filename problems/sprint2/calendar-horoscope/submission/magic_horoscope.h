#pragma once
#include <QString>

struct MonthItem {
    int from;
    QString label;
};

class DayMarker {

public:
    static int DaysPerMonth(int month, int year);
    DayMarker(std::vector<std::vector<MonthItem>> items);

    QString Get(int month, int day, int year);

private:
    std::vector<std::vector<MonthItem>> items_;
};

QString GetAnimalForEasternCalendar(int year);

QString GetElementForEasternCalendar(int year);

QString GetAnimalForTibetanCalendar(int year);

QString GetAnimalForZoroastrianCalendar(int year);

QString GetZodiac(int day, int month, int year);

QString GetTree(int day, int month, int year);

