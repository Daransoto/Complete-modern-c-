#include <iostream>
#include <vector>

template <typename T>
class PrettyPrinter {
	T* m_pData;

public:
	PrettyPrinter(T *data) : m_pData(data) {}
	void print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}
	T* get_data() {
		return m_pData;
	}
};

template<>
void PrettyPrinter<std::vector<std::vector<int>>>::print() {
	std::cout << "{" << std::endl;
	for (int i = 0; i < (*m_pData).size(); i++) {
		std::cout << "    {";
		for (int j = 0; j < (*m_pData)[i].size(); j++) {
			std::cout << (*m_pData)[i][j];
			if (j < (*m_pData)[i].size() - 1)
				std::cout << ",";
		}
		std::cout << "}";
		if (i < (*m_pData).size() - 1)
			std::cout << ",";
		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;
	
}

int main() {
	int idata = 5;
	float fdata = 3.2f;
	PrettyPrinter<int> pint(&idata);
	pint.print();
	PrettyPrinter<float> pfloat(&fdata);
	pfloat.print();
	std::vector<std::vector<int>> vdata{ {1,2,3},{4,5,6},{7,8,9} };
	PrettyPrinter< std::vector<std::vector<int>>> pvector(&vdata);
	pvector.print();
	return 0;
}