#ifndef DONUT_PARAM_JITPARAM_H
#define DONUT_PARAM_JITPARAM_H

namespace param {

class ParamAccessor;

class JITParam {
public:
    JITParam(const char* pParamName);
    ~JITParam();

    void loadCheck() const;
    template <typename T>
    const T& data() const;
private:
    /* 0x0 */ const char* mParamName;
    /* 0x4 */ ParamAccessor* mAccessor;
};

}

#endif
