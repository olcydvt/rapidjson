#include <filesystem>

#include "rapidjson/reader.h"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <rapidjson/filewritestream.h>

#include <iostream>
#include <string>

using namespace std;
using namespace rapidjson;

rapidjson::Document out_file_json;


void dumpJsonToFile() {
	FILE*  out_file;

	std::string dir = ".";
	auto file = dir + "/" + "annotations.json";
	out_file = fopen(file.c_str(), "w");

	char writeBuffer[65536];
	rapidjson::FileWriteStream os(out_file, writeBuffer, sizeof(writeBuffer));

	Writer<FileWriteStream> writer(os);
	out_file_json.Accept(writer);

    
	fclose(out_file);

}


int main(int argc, char** argv)
{
    out_file_json.SetObject();
    Value info(rapidjson::Type::kObjectType);
    
    rapidjson::Document::AllocatorType& allocator = out_file_json.GetAllocator();


    Value dt(rapidjson::Type::kStringType);
    std::string date_time{ "2021-05-12 10:19:54.174905" };
    dt.SetString(date_time.c_str(), allocator);

    info.AddMember("date_created", dt, allocator);
    info.AddMember("description", NULL, allocator);
    info.AddMember("url", NULL, allocator);
    info.AddMember("version", NULL, allocator);
    info.AddMember("contributor", NULL, allocator);
    
    Value val2;
    val2.CopyFrom(info, allocator);
    //val.  ["info"] = info;
    //out_file_json["info"].SetObject();
    out_file_json.AddMember("info", info, allocator); //AddMember(infoKey, info, allocator);
    out_file_json.AddMember("data", val2, allocator); //AddMember(infoKey, info, allocator);

    dumpJsonToFile();

    return 0;
}