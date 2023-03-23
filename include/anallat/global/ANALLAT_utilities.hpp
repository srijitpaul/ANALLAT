
// named variable interface ////////////////////////////////////////////////////
// FIXME: check redundant names and variable number limit

class VarName
{
  public:
    // constructor
    VarName(const std::string defName);
    // destructor
    virtual ~VarName(void) = default;
    // access
    std::string getName(const size_t i) const;
    void        setName(const size_t i, const std::string name);
    // test
    bool hasName(const size_t i) const;
  private:
    std::string                            defName_;
    std::unordered_map<size_t, std::string> name_;
};

// Type utilities //////////////////////////////////////////////////////////////
// pointer type test
  template <typename Derived, typename Base>
inline bool isDerivedFrom(const Base *pt)
{
  return (dynamic_cast<const Derived *>(pt) != nullptr);
}

// static logical or
template <bool... b>
struct static_or;

template <bool... tail>
struct static_or<true, tail...> : static_or<tail...> {};

template <bool... tail>
struct static_or<false, tail...> : std::false_type {};

template <>
struct static_or<> : std::true_type {};

// Environment /////////////////////////////////////////////////////////////////
void testFunction(void);

// String utilities ////////////////////////////////////////////////////////////
inline std::string extension(const std::string fileName)
{
    return fileName.substr(fileName.find_last_of(".") + 1);
}

template <typename T>
inline T strTo(const std::string &str)
{
    T buf;
    std::istringstream stream(str);

    stream >> buf;

    return buf;
}

// optimized specializations
template <>
inline float strTo<float>(const std::string &str)
{
    return strtof(str.c_str(), NULL);
}
template <>
inline double strTo<double>(const std::string &str)
{
    return strtod(str.c_str(), NULL);
}
template <>
inline int strTo<int>(const std::string &str)
{
    return static_cast<int>(strtol(str.c_str(), NULL, 10));
}
template <>
inline long strTo<long>(const std::string &str)
{
    return strtol(str.c_str(), NULL, 10);
}
template <>
inline std::string strTo<std::string>(const std::string &str)
{
    return str;
}

template <typename T>
inline std::string strFrom(const T x)
{
    std::ostringstream stream;

    stream << x;

    return stream.str();
}

//// specialization for vectors
//template<>
//inline DVec strTo<DVec>(const std::string &str)
//{
//    DVec                res;
//    std::vector<double> vbuf;
//    double              buf;
//    std::istringstream  stream(str);
//
//    while (!stream.eof())
//    {
//        stream >> buf;
//        vbuf.push_back(buf);
//    }
//    res = Map<DVec>(vbuf.data(), static_cast<Index>(vbuf.size()));
//
//    return res;
//}
//
//template<>
//inline IVec strTo<IVec>(const std::string &str)
//{
//    IVec                res;
//    std::vector<int>    vbuf;
//    int                 buf;
//    std::istringstream  stream(str);
//
//    while (!stream.eof())
//    {
//        stream >> buf;
//        vbuf.push_back(buf);
//    }
//    res = Map<IVec>(vbuf.data(), static_cast<Index>(vbuf.size()));
//
//    return res;
//}
//
//template<>
//inline UVec strTo<UVec>(const std::string &str)
//{
//    UVec                      res;
//    std::vector<unsigned int> vbuf;
//    unsigned int              buf;
//    std::istringstream        stream(str);
//
//    while (!stream.eof())
//    {
//        stream >> buf;
//        vbuf.push_back(buf);
//    }
//    res = Map<UVec>(vbuf.data(), static_cast<Index>(vbuf.size()));
//
//    return res;
//}
//
//template <typename T>
//void tokenReplace(std::string &str, const std::string token,
//                  const T &x, const std::string mark = "@")
//{
//    std::string fullToken = mark + token + mark;
//
//    auto pos = str.find(fullToken);
//    if (pos != std::string::npos)
//    {
//        str.replace(pos, fullToken.size(), strFrom(x));
//    }
//}
//
