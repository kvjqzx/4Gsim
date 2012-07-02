//
// Copyright (C) 2012 Calin Cerchez
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef DIAMETERUTILS_H_
#define DIAMETERUTILS_H_

#include <string>
#include "DiameterMessage_m.h"

#define IPV4_ADDRESS_TYPE	1

#define IPV4_ADDRESS_SIZE	4

class DiameterUtils {
private:
	AVP *createBaseAVP(unsigned avpCode, bool vendFlag, bool manFlag, bool privFlag, unsigned vendorId);

public:
	DiameterUtils();
	virtual ~DiameterUtils();

	AVP *createOctetStringAVP(unsigned avpCode, bool vendFlag, bool manFlag, bool privFlag, unsigned vendorId, unsigned len, const char *str);
	AVP *createUTF8StringAVP(unsigned avpCode, bool vendFlag, bool manFlag, bool privFlag, unsigned vendorId, std::string str);
	AVP *createAddressAVP(unsigned avpCode, bool vendFlag, bool manFlag, bool privFlag, unsigned vendorId, IPvXAddress addr);
	AVP *createUnsigned32AVP(unsigned avpCode, bool vendFlag, bool manFlag, bool privFlag, unsigned vendorId, unsigned val);
	AVP *createInteger32AVP(unsigned avpCode, bool vendFlag, bool manFlag, bool privFlag, unsigned vendorId, int val);
	AVP *createGroupedAVP(unsigned avpCode, bool vendFlag, bool manFlag, bool privFlag, unsigned vendorId, std::vector<AVP*> avps);
	DiameterHeader createHeader(unsigned commandCode, bool reqFlag, bool prxyFlag, bool errFlag, bool retrFlag, unsigned applId, unsigned hopByHopId, unsigned endToEndId);

	unsigned processUnsigned32AVP(AVP *unsigned32AVP);
	int processInteger32AVP(AVP *integer32AVP);
	char *processOctetStringAVP(AVP *octetStringAVP);
	std::string processUTF8String(AVP *utf8StringAVP);
	IPvXAddress processAddressAVP(AVP *addressAVP);
	std::vector<AVP*> processGroupedAVP(AVP *groupedAVP);

	AVP *findAVP(unsigned avpCode, std::vector<AVP*>avps);
	std::vector<AVP*> findAVPs(unsigned avpCode, std::vector<AVP*>avps);

	const char *avpName(unsigned avpCode);
	void deleteGroupedAVP(std::vector<AVP*>avps);
};

#endif /* DIAMETERUTILS_H_ */
