struct data_t {
	Int_t type, idx, nrows, barrel, layer, ladder, wafer, hybrid, Npar;
	Double_t v0, v1, v2, v3;
	Char_t Comment[10];
};
data_t Data[] = {
	{2,0,0,1,2, 1, 1, 1, 1, 0.02932,-0.01539, 0.00000, 0.00000,"duuH2101"},
	{2,0,0,1,2, 1, 1, 2, 0,-0.07639, 0.00000, 0.00000, 0.00000,"duuH2101"},
	{2,0,0,1,2, 1, 2, 1, 0, 0.04155, 0.00000, 0.00000, 0.00000,"duuH2201"},
	{2,0,0,1,2, 1, 2, 2, 0,-0.06445, 0.00000, 0.00000, 0.00000,"duuH2201"},
	{2,0,0,1,2, 1, 4, 1, 0,-0.01709, 0.00000, 0.00000, 0.00000,"duuH2401"},
	{2,0,0,1,2, 1, 4, 2, 2, 0.02528, 0.03418,-0.02188, 0.00000,"duuH2401"},
	{2,0,0,1,1, 2, 1, 1, 1,-0.03135,-0.01202, 0.00000, 0.00000,"duuH1102"},
	{2,0,0,1,1, 2, 1, 2, 1, 0.02761,-0.00990, 0.00000, 0.00000,"duuH1102"},
	{2,0,0,1,1, 2, 2, 1, 1,-0.01923,-0.01257, 0.00000, 0.00000,"duuH1202"},
	{2,0,0,1,1, 2, 2, 2, 1, 0.04089,-0.01386, 0.00000, 0.00000,"duuH1202"},
	{2,0,0,1,1, 2, 3, 1, 2,-0.01576,-0.02479,-0.00438, 0.00000,"duuH1302"},
	{2,0,0,1,1, 2, 3, 2, 2, 0.00049, 0.01113, 0.00371, 0.00000,"duuH1302"},
	{2,0,0,1,1, 2, 4, 1, 1,-0.00835,-0.02538, 0.00000, 0.00000,"duuH1402"},
	{2,0,0,1,1, 2, 4, 2, 1, 0.02057, 0.01385, 0.00000, 0.00000,"duuH1402"},
	{2,0,0,1,2, 3, 1, 1, 0, 0.01145, 0.00000, 0.00000, 0.00000,"duuH2103"},
	{2,0,0,1,2, 3, 1, 2, 0,-0.14807, 0.00000, 0.00000, 0.00000,"duuH2103"},
	{2,0,0,1,2, 3, 2, 1, 3, 0.07702,-0.04673, 0.00000,-0.02719,"duuH2203"},
	{2,0,0,1,2, 3, 3, 1, 2, 0.07357, 0.00000,-0.05291, 0.00000,"duuH2303"},
	{2,0,0,1,2, 3, 3, 2, 2,-0.06048, 0.02459, 0.02241, 0.00000,"duuH2303"},
	{2,0,0,1,2, 3, 4, 1, 2, 0.02058,-0.03493,-0.02785, 0.00000,"duuH2403"},
	{2,0,0,1,2, 3, 4, 2, 2,-0.01686, 0.02708, 0.02848, 0.00000,"duuH2403"},
	{2,0,0,1,1, 4, 2, 1, 1, 0.08459, 0.08706, 0.00000, 0.00000,"duuH1204"},
	{2,0,0,1,1, 4, 2, 2, 0,-0.07155, 0.00000, 0.00000, 0.00000,"duuH1204"},
	{2,0,0,1,1, 4, 3, 1, 0, 0.04081, 0.00000, 0.00000, 0.00000,"duuH1304"},
	{2,0,0,1,1, 4, 3, 2, 3,-0.00561, 0.06373, 0.00000, 0.02433,"duuH1304"},
	{2,0,0,1,1, 4, 4, 1, 0, 0.03942, 0.00000, 0.00000, 0.00000,"duuH1404"},
	{2,0,0,1,1, 4, 4, 2, 3, 0.11046, 0.04757, 0.00000, 0.01949,"duuH1404"},
	{2,0,0,1,2, 5, 1, 1, 2, 0.00336,-0.01409,-0.00694, 0.00000,"duuH2105"},
	{2,0,0,1,2, 5, 1, 2, 2, 0.01093, 0.02081, 0.00893, 0.00000,"duuH2105"},
	{2,0,0,1,2, 5, 2, 1, 1, 0.00760,-0.02019, 0.00000, 0.00000,"duuH2205"},
	{2,0,0,1,2, 5, 2, 2, 2, 0.01013, 0.02358, 0.00927, 0.00000,"duuH2205"},
	{2,0,0,1,2, 5, 3, 1, 3,-0.00371,-0.01683, 0.00000,-0.00334,"duuH2305"},
	{2,0,0,1,2, 5, 3, 2, 1, 0.02283, 0.01986, 0.00000, 0.00000,"duuH2305"},
	{2,0,0,1,2, 5, 4, 1, 3,-0.00765,-0.01690, 0.00000,-0.00313,"duuH2405"},
	{2,0,0,1,2, 5, 4, 2, 1, 0.02429, 0.02147, 0.00000, 0.00000,"duuH2405"},
	{2,0,0,1,1, 6, 1, 1, 1,-0.05656,-0.01402, 0.00000, 0.00000,"duuH1106"},
	{2,0,0,1,1, 6, 1, 2, 1,-0.00600, 0.02212, 0.00000, 0.00000,"duuH1106"},
	{2,0,0,1,1, 6, 2, 1, 1,-0.05550,-0.01995, 0.00000, 0.00000,"duuH1206"},
	{2,0,0,1,1, 6, 2, 2, 1,-0.00299, 0.02329, 0.00000, 0.00000,"duuH1206"},
	{2,0,0,1,2, 7, 1, 1, 1,-0.05154,-0.01281, 0.00000, 0.00000,"duuH2107"},
	{2,0,0,1,2, 7, 1, 2, 1,-0.03491, 0.01112, 0.00000, 0.00000,"duuH2107"},
	{2,0,0,1,2, 7, 2, 1, 1,-0.05162,-0.01440, 0.00000, 0.00000,"duuH2207"},
	{2,0,0,1,2, 7, 2, 2, 1,-0.03350, 0.00963, 0.00000, 0.00000,"duuH2207"},
	{2,0,0,1,2, 7, 3, 1, 2, 0.04371,-0.04064,-0.07393, 0.00000,"duuH2307"},
	{2,0,0,1,2, 7, 3, 2, 2,-0.14133, 0.03630, 0.09234, 0.00000,"duuH2307"},
	{2,0,0,1,2, 7, 4, 1, 2, 0.05105,-0.04857,-0.08001, 0.00000,"duuH2407"},
	{2,0,0,1,1, 8, 3, 1, 2, 0.04289,-0.05635,-0.02049, 0.00000,"duuH1308"},
	{2,0,0,1,1, 8, 3, 2, 2,-0.02824, 0.04293, 0.01781, 0.00000,"duuH1308"},
	{2,0,0,1,1, 8, 4, 1, 2, 0.04081,-0.04966,-0.02243, 0.00000,"duuH1408"},
	{2,0,0,1,1, 8, 4, 2, 2,-0.01597, 0.03790, 0.01859, 0.00000,"duuH1408"},

	{2,0,0,2,4, 1, 1, 1, 2,-0.02110,-0.03926,-0.02812, 0.00000,"duuH4101"},
	{2,0,0,2,4, 1, 1, 2, 1,-0.11462, 0.10653, 0.00000, 0.00000,"duuH4101"},
	{2,0,0,2,4, 1, 2, 1, 2,-0.00360,-0.04464,-0.03138, 0.00000,"duuH4201"},
	{2,0,0,2,4, 1, 2, 2, 2,-0.05543, 0.03956, 0.02942, 0.00000,"duuH4201"},
	{2,0,0,2,4, 1, 3, 1, 2, 0.01427,-0.05029,-0.03098, 0.00000,"duuH4301"},
	{2,0,0,2,4, 1, 3, 2, 2,-0.04463, 0.04143, 0.02804, 0.00000,"duuH4301"},
	{2,0,0,2,3, 2, 1, 1, 2, 0.04324,-0.04599, 0.01922, 0.00000,"duuH3102"},
	{2,0,0,2,3, 2, 1, 2, 2, 0.02030, 0.04114,-0.02357, 0.00000,"duuH3102"},
	{2,0,0,2,3, 2, 2, 1, 2, 0.05026,-0.05036, 0.02087, 0.00000,"duuH3202"},
	{2,0,0,2,3, 2, 2, 2, 2, 0.02174, 0.04463,-0.02322, 0.00000,"duuH3202"},
	{2,0,0,2,3, 2, 3, 1, 2, 0.04886,-0.04440, 0.01971, 0.00000,"duuH3302"},
	{2,0,0,2,3, 2, 3, 2, 2, 0.03400, 0.03630,-0.02164, 0.00000,"duuH3302"},
	{2,0,0,2,3, 2, 4, 1, 0, 0.09042, 0.00000, 0.00000, 0.00000,"duuH3402"},
	{2,0,0,2,3, 2, 4, 2, 0,-0.00001, 0.00000, 0.00000, 0.00000,"duuH3402"},
	{2,0,0,2,3, 2, 5, 2, 0,-0.03785, 0.00000, 0.00000, 0.00000,"duuH3502"},
	{2,0,0,2,3, 2, 6, 2, 2,-0.06025, 0.04504, 0.05721, 0.00000,"duuH3602"},
	{2,0,0,2,4, 3, 1, 1, 3,-0.02786, 0.00000, 0.00000,-0.00782,"duuH4103"},
	{2,0,0,2,4, 3, 1, 2, 0,-0.01656, 0.00000, 0.00000, 0.00000,"duuH4103"},
	{2,0,0,2,4, 3, 2, 1, 3,-0.02181, 0.00000, 0.00000,-0.00603,"duuH4203"},
	{2,0,0,2,4, 3, 2, 2, 3,-0.01306, 0.00000, 0.00925, 0.00747,"duuH4203"},
	{2,0,0,2,4, 3, 3, 1, 3,-0.02428, 0.00000, 0.00000,-0.00576,"duuH4303"},
	{2,0,0,2,4, 3, 3, 2, 2,-0.01119, 0.00000, 0.00823, 0.00000,"duuH4303"},
	{2,0,0,2,4, 3, 4, 1, 1,-0.02539,-0.01429, 0.00000, 0.00000,"duuH4403"},
	{2,0,0,2,4, 3, 4, 2, 1,-0.00634, 0.01123, 0.00000, 0.00000,"duuH4403"},
	{2,0,0,2,4, 3, 5, 1, 1,-0.02655,-0.01643, 0.00000, 0.00000,"duuH4503"},
	{2,0,0,2,4, 3, 5, 2, 1,-0.00366, 0.01132, 0.00000, 0.00000,"duuH4503"},
	{2,0,0,2,4, 3, 6, 1, 0, 0.01770, 0.00000, 0.00000, 0.00000,"duuH4603"},
	{2,0,0,2,4, 3, 6, 2, 0,-0.03097, 0.00000, 0.00000, 0.00000,"duuH4603"},
	{2,0,0,2,3, 4, 1, 1, 0,-0.03871, 0.00000, 0.00000, 0.00000,"duuH3104"},
	{2,0,0,2,3, 4, 1, 2, 1,-0.02030,-0.00517, 0.00000, 0.00000,"duuH3104"},
	{2,0,0,2,3, 4, 2, 1, 0, 0.02315, 0.00000, 0.00000, 0.00000,"duuH3204"},
	{2,0,0,2,3, 4, 2, 2, 0,-0.09875, 0.00000, 0.00000, 0.00000,"duuH3204"},
	{2,0,0,2,3, 4, 3, 1, 0,-0.03558, 0.00000, 0.00000, 0.00000,"duuH3304"},
	{2,0,0,2,3, 4, 3, 2, 1,-0.02777, 0.00780, 0.00000, 0.00000,"duuH3304"},
	{2,0,0,2,3, 4, 4, 1, 1,-0.07533,-0.00392, 0.00000, 0.00000,"duuH3404"},
	{2,0,0,2,3, 4, 4, 2, 1,-0.02508, 0.01415, 0.00000, 0.00000,"duuH3404"},
	{2,0,0,2,3, 4, 5, 1, 1,-0.05881,-0.02125, 0.00000, 0.00000,"duuH3504"},
	{2,0,0,2,3, 4, 5, 2, 1,-0.02131, 0.01725, 0.00000, 0.00000,"duuH3504"},
	{2,0,0,2,3, 4, 6, 1, 1,-0.05591,-0.02489, 0.00000, 0.00000,"duuH3604"},
	{2,0,0,2,3, 4, 6, 2, 1,-0.01885, 0.01538, 0.00000, 0.00000,"duuH3604"},
	{2,0,0,2,4, 5, 1, 1, 1,-0.11147,-0.00715, 0.00000, 0.00000,"duuH4105"},
	{2,0,0,2,4, 5, 1, 2, 0,-0.08653, 0.00000, 0.00000, 0.00000,"duuH4105"},
	{2,0,0,2,4, 5, 2, 1, 1,-0.10407,-0.01114, 0.00000, 0.00000,"duuH4205"},
	{2,0,0,2,4, 5, 2, 2, 1,-0.06485, 0.00997, 0.00000, 0.00000,"duuH4205"},
	{2,0,0,2,4, 5, 3, 1, 1,-0.08448,-0.01112, 0.00000, 0.00000,"duuH4305"},
	{2,0,0,2,4, 5, 3, 2, 0,-0.04036, 0.00000, 0.00000, 0.00000,"duuH4305"},
	{2,0,0,2,4, 5, 4, 1, 0,-0.07723, 0.00000, 0.00000, 0.00000,"duuH4405"},
	{2,0,0,2,4, 5, 4, 2, 0,-0.02162, 0.00000, 0.00000, 0.00000,"duuH4405"},
	{2,0,0,2,4, 5, 5, 1, 0,-0.06523, 0.00000, 0.00000, 0.00000,"duuH4505"},
	{2,0,0,2,4, 5, 5, 2, 0, 0.00521, 0.00000, 0.00000, 0.00000,"duuH4505"},
	{2,0,0,2,4, 5, 6, 1, 0,-0.04279, 0.00000, 0.00000, 0.00000,"duuH4605"},
	{2,0,0,2,4, 5, 6, 2, 0, 0.03568, 0.00000, 0.00000, 0.00000,"duuH4605"},
	{2,0,0,2,3, 6, 1, 1, 0,-0.07823, 0.00000, 0.00000, 0.00000,"duuH3106"},
	{2,0,0,2,3, 6, 1, 2, 0,-0.04063, 0.00000, 0.00000, 0.00000,"duuH3106"},
	{2,0,0,2,3, 6, 2, 1, 0,-0.07813, 0.00000, 0.00000, 0.00000,"duuH3206"},
	{2,0,0,2,3, 6, 2, 2, 0,-0.03884, 0.00000, 0.00000, 0.00000,"duuH3206"},
	{2,0,0,2,3, 6, 3, 1, 0,-0.08050, 0.00000, 0.00000, 0.00000,"duuH3306"},
	{2,0,0,2,3, 6, 3, 2, 0,-0.03578, 0.00000, 0.00000, 0.00000,"duuH3306"},
	{2,0,0,2,3, 6, 4, 1, 0,-0.06490, 0.00000, 0.00000, 0.00000,"duuH3406"},
	{2,0,0,2,3, 6, 4, 2, 0,-0.04941, 0.00000, 0.00000, 0.00000,"duuH3406"},
	{2,0,0,2,3, 6, 5, 1, 0,-0.06631, 0.00000, 0.00000, 0.00000,"duuH3506"},
	{2,0,0,2,3, 6, 5, 2, 2,-0.04057, 0.00000, 0.01313, 0.00000,"duuH3506"},
	{2,0,0,2,3, 6, 6, 1, 0,-0.07099, 0.00000, 0.00000, 0.00000,"duuH3606"},
	{2,0,0,2,3, 6, 6, 2, 0,-0.03739, 0.00000, 0.00000, 0.00000,"duuH3606"},
	{2,0,0,2,4, 7, 1, 1, 1,-0.08942,-0.01335, 0.00000, 0.00000,"duuH4107"},
	{2,0,0,2,4, 7, 1, 2, 1,-0.05906, 0.01035, 0.00000, 0.00000,"duuH4107"},
	{2,0,0,2,4, 7, 2, 1, 1,-0.07594,-0.01228, 0.00000, 0.00000,"duuH4207"},
	{2,0,0,2,4, 7, 2, 2, 1,-0.04469, 0.01114, 0.00000, 0.00000,"duuH4207"},
	{2,0,0,2,4, 7, 3, 1, 1,-0.06281,-0.01677, 0.00000, 0.00000,"duuH4307"},
	{2,0,0,2,4, 7, 3, 2, 1,-0.03020, 0.01229, 0.00000, 0.00000,"duuH4307"},
	{2,0,0,2,4, 7, 4, 1, 3,-0.04095,-0.01318, 0.00000,-0.00272,"duuH4407"},
	{2,0,0,2,4, 7, 4, 2, 1,-0.02654, 0.01457, 0.00000, 0.00000,"duuH4407"},
	{2,0,0,2,4, 7, 5, 1, 1,-0.02781,-0.01967, 0.00000, 0.00000,"duuH4507"},
	{2,0,0,2,4, 7, 5, 2, 1,-0.00985, 0.01000, 0.00000, 0.00000,"duuH4507"},
	{2,0,0,2,4, 7, 6, 1, 1,-0.01936,-0.01973, 0.00000, 0.00000,"duuH4607"},
	{2,0,0,2,4, 7, 6, 2, 1,-0.00755, 0.01056, 0.00000, 0.00000,"duuH4607"},
	{2,0,0,2,3, 8, 4, 1, 0,-0.05031, 0.00000, 0.00000, 0.00000,"duuH3408"},
	{2,0,0,2,3, 8, 4, 2, 0, 0.01043, 0.00000, 0.00000, 0.00000,"duuH3408"},
	{2,0,0,2,3, 8, 5, 1, 0,-0.04723, 0.00000, 0.00000, 0.00000,"duuH3508"},
	{2,0,0,2,3, 8, 5, 2, 0, 0.00738, 0.00000, 0.00000, 0.00000,"duuH3508"},
	{2,0,0,2,3, 8, 6, 1, 0,-0.05446, 0.00000, 0.00000, 0.00000,"duuH3608"},
	{2,0,0,2,3, 8, 6, 2, 3, 0.02210, 0.00000, 0.00000, 0.00817,"duuH3608"},
	{2,0,0,2,4, 9, 1, 1, 1, 0.03831,-0.01128, 0.00000, 0.00000,"duuH4109"},
	{2,0,0,2,4, 9, 1, 2, 1, 0.07051, 0.01289, 0.00000, 0.00000,"duuH4109"},
	{2,0,0,2,4, 9, 2, 1, 1, 0.02805,-0.01154, 0.00000, 0.00000,"duuH4209"},
	{2,0,0,2,4, 9, 2, 2, 1, 0.05774, 0.01463, 0.00000, 0.00000,"duuH4209"},
	{2,0,0,2,4, 9, 3, 1, 0, 0.02968, 0.00000, 0.00000, 0.00000,"duuH4309"},
	{2,0,0,2,4, 9, 3, 2, 1, 0.04045, 0.01458, 0.00000, 0.00000,"duuH4309"},
	{2,0,0,2,4, 9, 4, 2, 0, 0.03542, 0.00000, 0.00000, 0.00000,"duuH4409"},
	{2,0,0,2,4, 9, 5, 2, 0, 0.02282, 0.00000, 0.00000, 0.00000,"duuH4509"},
	{2,0,0,2,4, 9, 6, 2, 0, 0.02267, 0.00000, 0.00000, 0.00000,"duuH4609"},
	{2,0,0,2,3,10, 1, 1, 1, 0.05089,-0.02606, 0.00000, 0.00000,"duuH3110"},
	{2,0,0,2,3,10, 1, 2, 1, 0.07004, 0.02113, 0.00000, 0.00000,"duuH3110"},
	{2,0,0,2,3,10, 2, 1, 1, 0.05557,-0.01951, 0.00000, 0.00000,"duuH3210"},
	{2,0,0,2,3,10, 2, 2, 1, 0.07170, 0.02138, 0.00000, 0.00000,"duuH3210"},
	{2,0,0,2,3,10, 3, 1, 0, 0.06025, 0.00000, 0.00000, 0.00000,"duuH3310"},
	{2,0,0,2,3,10, 3, 2, 1, 0.07272, 0.01561, 0.00000, 0.00000,"duuH3310"},
	{2,0,0,2,3,10, 5, 1, 3,-0.02392, 0.00000, 0.00000,-0.04174,"duuH3510"},
	{2,0,0,2,3,10, 5, 2, 1,-0.02603, 0.05554, 0.00000, 0.00000,"duuH3510"},
	{2,0,0,2,3,10, 6, 1, 1,-0.01228,-0.04902, 0.00000, 0.00000,"duuH3610"},
	{2,0,0,2,3,10, 6, 2, 1, 0.01536, 0.06124, 0.00000, 0.00000,"duuH3610"},
	{2,0,0,2,4,11, 4, 1, 2, 0.05322,-0.02859,-0.09969, 0.00000,"duuH4411"},
	{2,0,0,2,4,11, 4, 2, 2,-0.11056, 0.01446, 0.10004, 0.00000,"duuH4411"},
	{2,0,0,2,4,11, 5, 1, 2, 0.02505,-0.02636,-0.09969, 0.00000,"duuH4511"},
	{2,0,0,2,4,11, 5, 2, 2,-0.13243, 0.00000, 0.11050, 0.00000,"duuH4511"},
	{2,0,0,2,4,11, 6, 1, 2, 0.02122,-0.05426,-0.08591, 0.00000,"duuH4611"},
	{2,0,0,2,4,11, 6, 2, 2,-0.17526, 0.00000, 0.11661, 0.00000,"duuH4611"},
	{2,0,0,2,3,12, 1, 1, 2, 0.01557, 0.00000,-0.00893, 0.00000,"duuH3112"},
	{2,0,0,2,3,12, 1, 2, 2,-0.01504, 0.00000, 0.00615, 0.00000,"duuH3112"},
	{2,0,0,2,3,12, 2, 1, 3,-0.00239, 0.00000,-0.00990,-0.00414,"duuH3212"},
	{2,0,0,2,3,12, 2, 2, 2,-0.01139, 0.00000, 0.00727, 0.00000,"duuH3212"},
	{2,0,0,2,3,12, 3, 1, 2, 0.00191, 0.00000,-0.00873, 0.00000,"duuH3312"},
	{2,0,0,2,3,12, 3, 2, 0,-0.04890, 0.00000, 0.00000, 0.00000,"duuH3312"},

	{2,0,0,3,6, 1, 1, 1, 0,-0.09253, 0.00000, 0.00000, 0.00000,"duuH6101"},
	{2,0,0,3,6, 1, 1, 2, 0,-0.05619, 0.00000, 0.00000, 0.00000,"duuH6101"},
	{2,0,0,3,6, 1, 2, 1, 0,-0.06885, 0.00000, 0.00000, 0.00000,"duuH6201"},
	{2,0,0,3,6, 1, 2, 2, 0,-0.07908, 0.00000, 0.00000, 0.00000,"duuH6201"},
	{2,0,0,3,6, 1, 3, 1, 0, 0.02680, 0.00000, 0.00000, 0.00000,"duuH6301"},
	{2,0,0,3,6, 1, 4, 1, 3, 0.09815, 0.00000,-0.02642,-0.01531,"duuH6401"},
	{2,0,0,3,6, 1, 4, 2, 3,-0.03923, 0.00000, 0.07039, 0.04815,"duuH6401"},
	{2,0,0,3,6, 1, 5, 1, 3, 0.05429, 0.00000,-0.02093,-0.01148,"duuH6501"},
	{2,0,0,3,6, 1, 6, 1, 2, 0.11990, 0.00000,-0.01915, 0.00000,"duuH6601"},
	{2,0,0,3,6, 1, 6, 2, 2, 0.03808,-0.01741, 0.01815, 0.00000,"duuH6601"},
	{2,0,0,3,6, 1, 7, 1, 2, 0.13095, 0.00000,-0.02565, 0.00000,"duuH6701"},
	{2,0,0,3,6, 1, 7, 2, 2, 0.04036,-0.01767, 0.01904, 0.00000,"duuH6701"},
	{2,0,0,3,5, 2, 1, 1, 3, 0.01005, 0.00000,-0.04414,-0.01236,"duuH5102"},
	{2,0,0,3,5, 2, 1, 2, 3,-0.06371, 0.00000, 0.04761, 0.01261,"duuH5102"},
	{2,0,0,3,5, 2, 2, 1, 2, 0.02127, 0.00000,-0.03977, 0.00000,"duuH5202"},
	{2,0,0,3,5, 2, 2, 2, 2,-0.08879, 0.00000, 0.03852, 0.00000,"duuH5202"},
	{2,0,0,3,5, 2, 3, 1, 3, 0.00932, 0.00000,-0.04554,-0.01332,"duuH5302"},
	{2,0,0,3,5, 2, 3, 2, 3,-0.06954, 0.00000, 0.04524, 0.01202,"duuH5302"},
	{2,0,0,3,5, 2, 4, 1, 3, 0.00531, 0.00000,-0.04596,-0.01373,"duuH5402"},
	{2,0,0,3,5, 2, 4, 2, 3,-0.06536, 0.00000, 0.04615, 0.01411,"duuH5402"},
	{2,0,0,3,5, 2, 5, 1, 3, 0.01171, 0.00000, 0.00000,-0.02134,"duuH5502"},
	{2,0,0,3,5, 2, 5, 2, 1,-0.10242,-0.04038, 0.00000, 0.00000,"duuH5502"},
	{2,0,0,3,5, 2, 6, 1, 3, 0.01304, 0.00000, 0.00000,-0.02278,"duuH5602"},
	{2,0,0,3,5, 2, 6, 2, 1,-0.12902,-0.03229, 0.00000, 0.00000,"duuH5602"},
	{2,0,0,3,5, 2, 7, 1, 3, 0.02016, 0.00000, 0.00000,-0.02895,"duuH5702"},
	{2,0,0,3,5, 2, 7, 2, 0,-0.15576, 0.00000, 0.00000, 0.00000,"duuH5702"},
	{2,0,0,3,6, 3, 1, 1, 3, 0.02450, 0.00000,-0.03215,-0.01701,"duuH6103"},
	{2,0,0,3,6, 3, 1, 2, 3,-0.08083, 0.00000, 0.03107, 0.01392,"duuH6103"},
	{2,0,0,3,6, 3, 2, 1, 3, 0.03834, 0.00000,-0.02986,-0.01619,"duuH6203"},
	{2,0,0,3,6, 3, 2, 2, 3,-0.03681, 0.00000, 0.03167, 0.01648,"duuH6203"},
	{2,0,0,3,6, 3, 3, 1, 3, 0.05260, 0.00000,-0.02845,-0.01753,"duuH6303"},
	{2,0,0,3,6, 3, 3, 2, 3,-0.02821, 0.00000, 0.03148, 0.01515,"duuH6303"},
	{2,0,0,3,6, 3, 4, 1, 3, 0.04458, 0.00000,-0.01916,-0.01388,"duuH6403"},
	{2,0,0,3,6, 3, 4, 2, 0,-0.12108, 0.00000, 0.00000, 0.00000,"duuH6403"},
	{2,0,0,3,6, 3, 5, 1, 3, 0.06034, 0.00000,-0.01869,-0.01416,"duuH6503"},
	{2,0,0,3,6, 3, 5, 2, 3,-0.03191, 0.00000, 0.02085, 0.01158,"duuH6503"},
	{2,0,0,3,6, 3, 6, 1, 3, 0.07196, 0.00000,-0.01912,-0.01241,"duuH6603"},
	{2,0,0,3,6, 3, 6, 2, 3, 0.00293, 0.00000, 0.02022, 0.01247,"duuH6603"},
	{2,0,0,3,5, 4, 1, 1, 0,-0.04041, 0.00000, 0.00000, 0.00000,"duuH5104"},
	{2,0,0,3,5, 4, 1, 2, 0,-0.03858, 0.00000, 0.00000, 0.00000,"duuH5104"},
	{2,0,0,3,5, 4, 2, 1, 2,-0.04352, 0.00000, 0.00460, 0.00000,"duuH5204"},
	{2,0,0,3,5, 4, 2, 2, 1,-0.03650, 0.00950, 0.00000, 0.00000,"duuH5204"},
	{2,0,0,3,5, 4, 3, 1, 2,-0.03708, 0.00000, 0.00396, 0.00000,"duuH5304"},
	{2,0,0,3,5, 4, 3, 2, 0,-0.05405, 0.00000, 0.00000, 0.00000,"duuH5304"},
	{2,0,0,3,5, 4, 4, 1, 2,-0.04407, 0.00000, 0.00352, 0.00000,"duuH5404"},
	{2,0,0,3,5, 4, 4, 2, 0,-0.02668, 0.00000, 0.00000, 0.00000,"duuH5404"},
	{2,0,0,3,5, 4, 5, 1, 1,-0.03919,-0.00656, 0.00000, 0.00000,"duuH5504"},
	{2,0,0,3,5, 4, 5, 2, 1,-0.01848, 0.00744, 0.00000, 0.00000,"duuH5504"},
	{2,0,0,3,5, 4, 6, 1, 1,-0.03300,-0.00883, 0.00000, 0.00000,"duuH5604"},
	{2,0,0,3,5, 4, 6, 2, 1,-0.01169, 0.00804, 0.00000, 0.00000,"duuH5604"},
	{2,0,0,3,5, 4, 7, 1, 1,-0.02624,-0.01110, 0.00000, 0.00000,"duuH5704"},
	{2,0,0,3,5, 4, 7, 2, 3,-0.00923, 0.01264, 0.00000, 0.00555,"duuH5704"},
	{2,0,0,3,6, 5, 1, 1, 3,-0.06378, 0.00000, 0.00000,-0.00869,"duuH6105"},
	{2,0,0,3,6, 5, 1, 2, 1, 0.01478, 0.11111, 0.00000, 0.00000,"duuH6105"},
	{2,0,0,3,6, 5, 2, 1, 3,-0.05571, 0.00000, 0.00000,-0.01375,"duuH6205"},
	{2,0,0,3,6, 5, 3, 1, 0,-0.03485, 0.00000, 0.00000, 0.00000,"duuH6305"},
	{2,0,0,3,6, 5, 4, 1, 0, 0.04654, 0.00000, 0.00000, 0.00000,"duuH6405"},
	{2,0,0,3,6, 5, 4, 2, 0,-0.11037, 0.00000, 0.00000, 0.00000,"duuH6405"},
	{2,0,0,3,6, 5, 5, 1, 3,-0.05527, 0.00000, 0.00000,-0.00449,"duuH6505"},
	{2,0,0,3,6, 5, 5, 2, 0,-0.03008, 0.00000, 0.00000, 0.00000,"duuH6505"},
	{2,0,0,3,6, 5, 6, 1, 3,-0.05057, 0.00000, 0.00000,-0.00311,"duuH6605"},
	{2,0,0,3,6, 5, 6, 2, 1,-0.02757, 0.00679, 0.00000, 0.00000,"duuH6605"},
	{2,0,0,3,6, 5, 7, 1, 3,-0.05309, 0.00000, 0.00000,-0.00428,"duuH6705"},
	{2,0,0,3,6, 5, 7, 2, 0,-0.02765, 0.00000, 0.00000, 0.00000,"duuH6705"},
	{2,0,0,3,5, 6, 1, 1, 0, 0.00296, 0.00000, 0.00000, 0.00000,"duuH5106"},
	{2,0,0,3,5, 6, 1, 2, 0, 0.00652, 0.00000, 0.00000, 0.00000,"duuH5106"},
	{2,0,0,3,5, 6, 2, 1, 0, 0.01032, 0.00000, 0.00000, 0.00000,"duuH5206"},
	{2,0,0,3,5, 6, 2, 2, 2,-0.00001, 0.00000, 0.01128, 0.00000,"duuH5206"},
	{2,0,0,3,5, 6, 3, 1, 0, 0.02877, 0.00000, 0.00000, 0.00000,"duuH5306"},
	{2,0,0,3,5, 6, 3, 2, 0, 0.02895, 0.00000, 0.00000, 0.00000,"duuH5306"},
	{2,0,0,3,5, 6, 4, 1, 0, 0.04450, 0.00000, 0.00000, 0.00000,"duuH5406"},
	{2,0,0,3,5, 6, 4, 2, 1, 0.03359, 0.00487, 0.00000, 0.00000,"duuH5406"},
	{2,0,0,3,5, 6, 5, 1, 0, 0.03254, 0.00000, 0.00000, 0.00000,"duuH5506"},
	{2,0,0,3,5, 6, 5, 2, 2, 0.04820, 0.00000,-0.00561, 0.00000,"duuH5506"},
	{2,0,0,3,5, 6, 6, 2, 2, 0.05406, 0.00000,-0.00543, 0.00000,"duuH5606"},
	{2,0,0,3,5, 6, 7, 1, 0, 0.05832, 0.00000, 0.00000, 0.00000,"duuH5706"},
	{2,0,0,3,5, 6, 7, 2, 3, 0.06447, 0.00000,-0.00604,-0.00457,"duuH5706"},
	{2,0,0,3,6, 7, 2, 1, 1,-0.18964, 0.01201, 0.00000, 0.00000,"duuH6207"},
	{2,0,0,3,6, 7, 2, 2, 1,-0.19237,-0.01706, 0.00000, 0.00000,"duuH6207"},
	{2,0,0,3,6, 7, 3, 2, 0,-0.19583, 0.00000, 0.00000, 0.00000,"duuH6307"},
	{2,0,0,3,5, 8, 2, 1, 2,-0.03433, 0.02093,-0.01914, 0.00000,"duuH5208"},
	{2,0,0,3,5, 8, 2, 2, 1,-0.17674,-0.02148, 0.00000, 0.00000,"duuH5208"},
	{2,0,0,3,5, 8, 3, 1, 3,-0.05589, 0.00000, 0.00000,-0.01610,"duuH5308"},
	{2,0,0,3,5, 8, 3, 2, 0,-0.20716, 0.00000, 0.00000, 0.00000,"duuH5308"},
	{2,0,0,3,5, 8, 4, 1, 2,-0.06989, 0.02567,-0.01719, 0.00000,"duuH5408"},
	{2,0,0,3,5, 8, 4, 2, 0,-0.19294, 0.00000, 0.00000, 0.00000,"duuH5408"},
	{2,0,0,3,5, 8, 5, 1, 1,-0.09018,-0.00777, 0.00000, 0.00000,"duuH5508"},
	{2,0,0,3,5, 8, 5, 2, 0,-0.08350, 0.00000, 0.00000, 0.00000,"duuH5508"},
	{2,0,0,3,5, 8, 6, 1, 1,-0.09551,-0.00549, 0.00000, 0.00000,"duuH5608"},
	{2,0,0,3,5, 8, 6, 2, 0,-0.08574, 0.00000, 0.00000, 0.00000,"duuH5608"},
	{2,0,0,3,5, 8, 7, 1, 2,-0.09572, 0.00000, 0.00449, 0.00000,"duuH5708"},
	{2,0,0,3,5, 8, 7, 2, 0,-0.09493, 0.00000, 0.00000, 0.00000,"duuH5708"},
	{2,0,0,3,6, 9, 1, 1, 1,-0.15852,-0.05244, 0.00000, 0.00000,"duuH6109"},
	{2,0,0,3,6, 9, 1, 2, 2,-0.26823, 0.00867, 0.05877, 0.00000,"duuH6109"},
	{2,0,0,3,6, 9, 2, 1, 2,-0.17493, 0.00000,-0.02163, 0.00000,"duuH6209"},
	{2,0,0,3,6, 9, 2, 2, 0,-0.20935, 0.00000, 0.00000, 0.00000,"duuH6209"},
	{2,0,0,3,6, 9, 3, 1, 1,-0.11686,-0.05818, 0.00000, 0.00000,"duuH6309"},
	{2,0,0,3,6, 9, 3, 2, 2,-0.19416, 0.03735, 0.01810, 0.00000,"duuH6309"},
	{2,0,0,3,6, 9, 4, 1, 0,-0.17224, 0.00000, 0.00000, 0.00000,"duuH6409"},
	{2,0,0,3,6, 9, 4, 2, 0,-0.13415, 0.00000, 0.00000, 0.00000,"duuH6409"},
	{2,0,0,3,6, 9, 5, 1, 0,-0.15431, 0.00000, 0.00000, 0.00000,"duuH6509"},
	{2,0,0,3,6, 9, 6, 1, 0,-0.13587, 0.00000, 0.00000, 0.00000,"duuH6609"},
	{2,0,0,3,6, 9, 6, 2, 0,-0.07758, 0.00000, 0.00000, 0.00000,"duuH6609"},
	{2,0,0,3,6, 9, 7, 1, 0,-0.11439, 0.00000, 0.00000, 0.00000,"duuH6709"},
	{2,0,0,3,5,10, 1, 1, 1, 0.04796,-0.01051, 0.00000, 0.00000,"duuH5110"},
	{2,0,0,3,5,10, 1, 2, 1, 0.04349, 0.00633, 0.00000, 0.00000,"duuH5110"},
	{2,0,0,3,5,10, 2, 1, 1, 0.04905,-0.01202, 0.00000, 0.00000,"duuH5210"},
	{2,0,0,3,5,10, 2, 2, 2, 0.04956, 0.00000, 0.00653, 0.00000,"duuH5210"},
	{2,0,0,3,5,10, 3, 1, 1, 0.09312,-0.00975, 0.00000, 0.00000,"duuH5310"},
	{2,0,0,3,5,10, 3, 2, 2, 0.05149, 0.00000, 0.00606, 0.00000,"duuH5310"},
	{2,0,0,3,5,10, 4, 1, 2, 0.12477, 0.00000,-0.06512, 0.00000,"duuH5410"},
	{2,0,0,3,5,10, 4, 2, 2, 0.05525, 0.00000, 0.00348, 0.00000,"duuH5410"},
	{2,0,0,3,5,10, 5, 1, 1, 0.03518,-0.01868, 0.00000, 0.00000,"duuH5510"},
	{2,0,0,3,5,10, 5, 2, 1, 0.06417, 0.01186, 0.00000, 0.00000,"duuH5510"},
	{2,0,0,3,5,10, 6, 1, 1, 0.03268,-0.02151, 0.00000, 0.00000,"duuH5610"},
	{2,0,0,3,5,10, 6, 2, 0, 0.04587, 0.00000, 0.00000, 0.00000,"duuH5610"},
	{2,0,0,3,5,10, 7, 1, 1, 0.03245,-0.02174, 0.00000, 0.00000,"duuH5710"},
	{2,0,0,3,5,10, 7, 2, 1, 0.06553, 0.01706, 0.00000, 0.00000,"duuH5710"},
	{2,0,0,3,6,11, 1, 2, 2, 0.03557, 0.01636, 0.00528, 0.00000,"duuH6111"},
	{2,0,0,3,6,11, 2, 1, 2,-0.00025,-0.01886,-0.00701, 0.00000,"duuH6211"},
	{2,0,0,3,6,11, 2, 2, 2, 0.02435, 0.01794, 0.00635, 0.00000,"duuH6211"},
	{2,0,0,3,5,12, 1, 1, 1,-0.01973,-0.00469, 0.00000, 0.00000,"duuH5112"},
	{2,0,0,3,5,12, 1, 2, 0, 0.04175, 0.00000, 0.00000, 0.00000,"duuH5112"},
	{2,0,0,3,5,12, 2, 1, 0,-0.00623, 0.00000, 0.00000, 0.00000,"duuH5212"},
	{2,0,0,3,5,12, 2, 2, 0, 0.05093, 0.00000, 0.00000, 0.00000,"duuH5212"},
	{2,0,0,3,5,12, 3, 1, 0, 0.00399, 0.00000, 0.00000, 0.00000,"duuH5312"},
	{2,0,0,3,5,12, 3, 2, 0, 0.06290, 0.00000, 0.00000, 0.00000,"duuH5312"},
	{2,0,0,3,5,12, 4, 1, 1, 0.02859,-0.02187, 0.00000, 0.00000,"duuH5412"},
	{2,0,0,3,5,12, 4, 2, 1, 0.07728,-0.00175, 0.00000, 0.00000,"duuH5412"},
	{2,0,0,3,5,12, 5, 1, 0, 0.02297, 0.00000, 0.00000, 0.00000,"duuH5512"},
	{2,0,0,3,5,12, 5, 2, 1, 0.06944, 0.00689, 0.00000, 0.00000,"duuH5512"},
	{2,0,0,3,5,12, 6, 1, 0, 0.03182, 0.00000, 0.00000, 0.00000,"duuH5612"},
	{2,0,0,3,5,12, 6, 2, 1, 0.07907, 0.00632, 0.00000, 0.00000,"duuH5612"},
	{2,0,0,3,5,12, 7, 1, 1, 0.04443,-0.00711, 0.00000, 0.00000,"duuH5712"},
	{2,0,0,3,5,12, 7, 2, 1, 0.08548, 0.00849, 0.00000, 0.00000,"duuH5712"},
	{2,0,0,3,6,13, 1, 1, 2, 0.03704, 0.00000,-0.02983, 0.00000,"duuH6113"},
	{2,0,0,3,6,13, 1, 2, 2, 0.00374, 0.01450, 0.02327, 0.00000,"duuH6113"},
	{2,0,0,3,6,13, 2, 1, 2, 0.04577, 0.00000,-0.03459, 0.00000,"duuH6213"},
	{2,0,0,3,6,13, 2, 2, 2, 0.01141, 0.01489, 0.02485, 0.00000,"duuH6213"},
	{2,0,0,3,6,13, 3, 1, 2, 0.07054,-0.03420,-0.03362, 0.00000,"duuH6313"},
	{2,0,0,3,6,13, 3, 2, 2, 0.00594, 0.02533, 0.02335, 0.00000,"duuH6313"},
	{2,0,0,3,6,13, 4, 1, 2, 0.03701, 0.00000,-0.02234, 0.00000,"duuH6413"},
	{2,0,0,3,6,13, 4, 2, 2, 0.04987, 0.00938, 0.01241, 0.00000,"duuH6413"},
	{2,0,0,3,6,13, 5, 1, 2, 0.04854,-0.01733,-0.01782, 0.00000,"duuH6513"},
	{2,0,0,3,6,13, 6, 1, 2, 0.05852,-0.02493,-0.01103, 0.00000,"duuH6613"},
	{2,0,0,3,6,13, 7, 1, 2, 0.07121,-0.01982,-0.01084, 0.00000,"duuH6713"},
	{2,0,0,3,6,13, 7, 2, 2, 0.06537, 0.01424, 0.00725, 0.00000,"duuH6713"},
	{2,0,0,3,5,14, 1, 1, 1, 0.07323,-0.00797, 0.00000, 0.00000,"duuH5114"},
	{2,0,0,3,5,14, 1, 2, 1, 0.06245, 0.00597, 0.00000, 0.00000,"duuH5114"},
	{2,0,0,3,5,14, 2, 1, 0, 0.06787, 0.00000, 0.00000, 0.00000,"duuH5214"},
	{2,0,0,3,5,14, 2, 2, 0, 0.11628, 0.00000, 0.00000, 0.00000,"duuH5214"},
	{2,0,0,3,5,14, 3, 1, 2, 0.07735,-0.00393,-0.00693, 0.00000,"duuH5314"},
	{2,0,0,3,5,14, 3, 2, 2, 0.05010, 0.00000, 0.04498, 0.00000,"duuH5314"},
	{2,0,0,3,5,14, 4, 1, 0, 0.07713, 0.00000, 0.00000, 0.00000,"duuH5414"},
	{2,0,0,3,5,14, 4, 2, 2, 0.04466, 0.00000, 0.04408, 0.00000,"duuH5414"},
	{2,0,0,3,5,14, 5, 1, 3, 0.06192, 0.00000,-0.03300,-0.07293,"duuH5514"},
	{2,0,0,3,5,14, 5, 2, 2, 0.05924, 0.03207, 0.02751, 0.00000,"duuH5514"},
	{2,0,0,3,5,14, 6, 1, 0, 0.16514, 0.00000, 0.00000, 0.00000,"duuH5614"},
	{2,0,0,3,5,14, 6, 2, 2, 0.08816, 0.00000, 0.02075, 0.00000,"duuH5614"},
	{2,0,0,3,5,14, 7, 1, 2, 0.15460, 0.00000,-0.02273, 0.00000,"duuH5714"},
	{2,0,0,3,5,14, 7, 2, 2, 0.10109, 0.00000, 0.01988, 0.00000,"duuH5714"},
	{2,0,0,3,6,15, 5, 1, 1,-0.12698,-0.01120, 0.00000, 0.00000,"duuH6515"},
	{2,0,0,3,6,15, 5, 2, 0,-0.12098, 0.00000, 0.00000, 0.00000,"duuH6515"},
	{2,0,0,3,6,15, 6, 1, 1,-0.15229,-0.01397, 0.00000, 0.00000,"duuH6615"},
	{2,0,0,3,6,15, 6, 2, 1,-0.12480, 0.01464, 0.00000, 0.00000,"duuH6615"},
	{2,0,0,3,6,15, 7, 1, 1,-0.16963,-0.01021, 0.00000, 0.00000,"duuH6715"},
	{2,0,0,3,6,15, 7, 2, 0,-0.13074, 0.00000, 0.00000, 0.00000,"duuH6715"},
	{2,0,0,3,5,16, 5, 1, 0,-0.09907, 0.00000, 0.00000, 0.00000,"duuH5516"},
	{2,0,0,3,5,16, 5, 2, 0,-0.00634, 0.00000, 0.00000, 0.00000,"duuH5516"},
	{2,0,0,3,5,16, 6, 1, 3,-0.09769, 0.00000,-0.03352,-0.01064,"duuH5616"},
	{2,0,0,3,5,16, 6, 2, 0,-0.12495, 0.00000, 0.00000, 0.00000,"duuH5616"},
	{2,0,0,3,5,16, 7, 1, 2,-0.06748, 0.00000,-0.03065, 0.00000,"duuH5716"},
	{2,0,0,3,5,16, 7, 2, 2,-0.14742,-0.01068, 0.02685, 0.00000,"duuH5716"}
};

