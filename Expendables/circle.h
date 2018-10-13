#ifndef CIRCLE_H
#define CIRCLE_H
#define ARREY_INIT_SIZE 100
#include <QObject>
#include <QDebug>
#include <QString>
class Circle : public QObject
{
    Q_OBJECT
public:
    void outputByArray(int m);
    void outputBySqlist(int m);
    void outputByQueue(int m);
    void outputByLinklist(int m);

signals:
    void begin();
public slots:
    int getLen() const {
           return len;
       }
    int getTheFirst() const {
           return thef;
       }
    QString getOutList()  {
        this->result = "";
        for (int i = 0;i < len;i++)
        {
            result += char(num[i]+'0');
            result += ' ';
        }
        return this->result;
       }
    void doSomething(int m, int n);
private:
    int num[ARREY_INIT_SIZE];
    int len;
    int thef;
    QString result;
};
#endif // CIRCLE_H
