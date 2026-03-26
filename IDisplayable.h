#ifndef IDISPLAYABLE_H
#define IDISPLAYABLE_H

class IDisplayable {
public:
    virtual ~IDisplayable() {}
    virtual void printDetails() const = 0;
};

#endif
