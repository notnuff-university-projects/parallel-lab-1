#ifndef F4_H
#define F4_H

#include "data.h"
#include "tthread.h"

class F4 : public TThread {
public:
    F4(Data* data);
    const std::vector<double>& getResult() const { return result; }

protected:
    void execute() override;

private:
    Data* data;
    std::vector<double> result;
};

#endif //F4_H