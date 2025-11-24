/*#include<iostream>
#include<fstream>
#include<vector>
int main(){
	
// Process 4 KB at a time (very safe, works for any file size)
std::ifstream file("powershell.exe", std::ios::binary);
std::vector<char> chunk(4096);

while (file.read(chunk.data(), chunk.size()) || file.gcount()) {
    std::streamsize bytes_read = file.gcount();
    // process the bytes in 'chunk' (0 to bytes_read-1)
 //   process_bytes(chunk.data(), bytes_read);
std::cout<<chunk.data(); 
}
std::cout<<chunk.data();
} */

#include<iostream>
#include<fstream>
#include<vector>
//#include<windows.h>
int main(int argv,char* argc[]){

	std::ifstream file(argc[0],std::ios::binary);

//	file.seekg(0,std::ios::end);
//	std::streamsize siz=file.tellg(); 
//	file.seekg(0,std::ios::beg);
file.seekg(0,std::ios::end);
size_t siz = file.tellg();
file.seekg(0,std::ios::beg);


	std::vector<char> buff(static_cast<size_t>(siz));
std::cout<<buff.max_size()<<"\n";
	if(!file.read(buff.data(),siz)){
		std::cout<<"error reading file";
	}
	//char arr[4096];
	//while(file.read(arr,4096)){
	//	buff.insert(buff.end(),arr,arr[4096]);

	//std::cout<<std::string(buff.begin(),buff.end())<<"\n";
	//std::cout<<(char*)buff.data();
	//}
for(long i =0;i<128000;i+=16){
	printf("%08zx   " ,i);
	
	for(long j=0;j<16;++j){
		if(i+j <128000){
			printf("%02X ",(unsigned char)buff[i+j]);
		}else {
			printf("   ");
	}
	}
	printf("   ");
	for(long j=0;j<16;++j){
		if((i+j)<128000){
			unsigned char c = buff[i+j];
			if(isprint(c)){
				putchar(c);
			}else{
				putchar('.');
			}
		}
		
	}
	printf("\n");
}
return 0;
}


