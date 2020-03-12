% Represent the Design Data section of the data dictionary 
% myDictionary_ex_API.sldd with a Simulink.data.dictionary.Section object named dDataSectObj.
myDictionaryObj = Simulink.data.dictionary.open('myDictionary_ex_API.sldd');
dDataSectObj = getSection(myDictionaryObj,'Design Data');
% Add an entry to the Design Data section of myDictionary_ex_API.sldd an entry myNewEntry with value 237.
addEntry(dDataSectObj,'myNewEntry',237);