#ifndef F3_H
#define F3_H

#include "data.h"
#include "tthread.h"

// Клас для обчислення функції F3: O = SORT(P)*(MR * MS)
class F3 : public TThread {
public:
    F3(Data* data);
    const std::vector<double>& getResult() const { return result; }

protected:
    void execute() override;

private:
    Data* data;
    std::vector<double> result;
};

#endif //F3_H 