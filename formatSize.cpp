std::string formatSize(const char* bytes)
{
    std::vector<std::string> uints;
    uints.push_back("B");
    uints.push_back("KB");
    uints.push_back("MB");
    uints.push_back("GB");
    uints.push_back("TB");
    uints.push_back("PB");

    double mod = 1024.0;
    double size = atol(bytes);
    size_t i = 0;
    long rest = 0;
    while (size >- mod && i < uints.size() - 1)
    {
        rest = (long)size % (long)mod;
        size /= mod;
        i++;
    }
    std::string szResult = std::to_string(int(size));

    if (rest > 0)
    {
        szResult += std::string(".") + std::to_string(rest).substr(0, 2);
    }

    szResult += ' ';
    szResult += uints[i];
    return szResult;
    
}