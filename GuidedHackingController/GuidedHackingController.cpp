#include <iostream>
#include "kernelInterface.hpp"
#include "offsets.hpp"


int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\guidedhacking");

	ULONG address = Driver.GetClientAddress();
	ULONG processId = Driver.GetProcessId();

	std::cout << " ClientAddress " <<std::hex << address << std::endl;
	std::cout << " ProcessId " << processId << std::endl;

	std::cout << "Hello World!\n";

	while (true)
	{
		uint32_t LocalPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(processId, address + hazedumper::signatures::dwLocalPlayer, sizeof(uint32_t));

		Driver.WriteVirtualMemory(processId, LocalPlayerAddress + hazedumper::netvars::m_flFlashMaxAlpha, 0.f, sizeof(0.f));
	}
}

