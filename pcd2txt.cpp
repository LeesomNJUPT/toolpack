//************************************
// Method:    pCloud2txt
// FullName:  Common::pCloud2txt
// Access:    public 
// Returns:   bool
// Qualifier: 原格式输出点云文件 注：使用string类型而不是用double是为了防止精度问题
//			  丢失小数点后面的数据
// Parameter: PointCloudT cloud
// Parameter: std::string txtName
//************************************
bool Common::pCloud2txt(PointCloudT cloud, std::string txtName)
{
	int Num = cloud.points.size();
	std::vector<string> X;
	std::vector<string> Y;
	std::vector<string> Z;
	for (size_t i = 0; i < cloud.points.size(); ++i)
	{
		X.push_back(std::to_string(cloud.points[i].x));
		Y.push_back(std::to_string(cloud.points[i].y));
		Z.push_back(std::to_string(cloud.points[i].z));
	}

	ofstream zos(txtName.c_str());
	for (int i = 0; i < Num; i++)
	{
		zos << X[i] << " " << Y[i] << " " << Z[i] << endl;
	}
	cout << "trans has done!!!" << endl;
	cin.get();
	return true;
}