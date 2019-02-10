#ifndef MODULE_ITF_H
#define MODULE_ITF_H


#include <exception>


class ModuleItf
{
public:

    virtual ~ModuleItf() = default;
    virtual bool setup() { return true; }
    virtual void loop() {}
    virtual void teardown() {}

protected:

    void terminate();
};


#endif // MODULE_ITF_H

