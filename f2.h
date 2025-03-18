#ifndef F2_H
#define F2_H

#include "data.h"
#include "tthread.h"

// Клас для обчислення функції F2: MK = MA*(MG*MZ) + TRANS(ML)
class F2 : public TThread {
public:
    F2(Data* data);
    const std::vector<std::vector<double>>& getResult() const { return result; }

protected:
    void execute() override;

private:
    Data* data;
    std::vector<std::vector<double>> result;
};

#endif //F2_H 