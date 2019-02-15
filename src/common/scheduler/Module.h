#ifndef MODULE_H
#define MODULE_H


class Module
{
public:

    virtual ~Module() = default;
    virtual void loop() = 0;

protected:

    enum Signal { EXIT };

    virtual void handleSignal(Signal signal) { propagateSignal(signal); }

    void propagateSignal(Signal signal);
    void becomeParentOf(Module& child);

    Module* m_parent = nullptr;
};


#endif // MODULE_H

