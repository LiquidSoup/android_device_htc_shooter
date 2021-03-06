/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "1.04.2000" || "1.40.1100" || "1.40.0000" || "1.40.1000")) {
         /* shooter */
        property_set("ro.build.fingerprint", "htc/htc_shooter/shooter:4.0.3/IML74K/560205.6:user/release-keys");
        property_set("ro.build.description", "2.95.651.6 CL560205 release-keys");
        property_set("ro.product.model", "Evo 3D CDMA");
        property_set("ro.product.device", "shooter");
        property_set("ro.carrier", "Sprint");
        property_set("gsm.operator.alpha", "sprint"
        property_set("gsm.operator.numeric", "310120");
        property_set("ro.cdma.home.operator.alpha", "sprint");
        property_set("ro.cdma.home.operator.numeric", "310120");
    }else if (strstr(bootloader, "1.50.5050" || "1.50.0000")) {
        /* shootervm */
        property_set("ro.build.fingerprint", "virgin_mobile/htc_shooter/shooter:4.0.3/IML74K/372137.2:user/release-keys");
        property_set("ro.build.description", "1.13.652.2_R2 CL372137 release-keys");
        property_set("ro.product.model", "Evo V 4G");
        property_set("ro.product.device", "shootervm");
        property_set("ro.carrier", "Virgin Mobile");
        property_set("gsm.operator.alpha", "Virgin Mobile"
        property_set("gsm.operator.numeric", "311490");
        property_set("ro.cdma.home.operator.alpha", "Virgin Mobile");
        property_set("ro.cdma.home.operator.numeric", "311490");
    }
    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
