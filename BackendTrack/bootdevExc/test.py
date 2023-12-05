# def get_character_record(name, server, level, rank):
#     dic={
#         "name":name,
#         "server":server,
#         "level":level,
#         "rank":rank,
#         "id":f"{name}#{server}"
#     }
#     return dic



# my_info=get_character_record("ziadmostafa","server1",1212,200)



# print(my_info)



# car = {
#     'make': 'tesla',
#     'model': '3'
# }
# print(car['make'])
# # # Prints: tesla
# names = ["jack bronson", "jill mcarty", "john denver"]
# names_arr=[]
# names_dict = {}
# for name in names:
#     # .split() returns a list of strings
#     # where each string is a single word from the original
#     names_arr=name.split()
#     names_dict[names_arr[0]]=names_arr[1]

#     # here we update the dictionary
# #     names_dict[names_arr[0]] = names_arr[1]

# # print(names_dict)
# print(names_dict)
# Prints: {'jack': 'bronson', 'jill': 'mcarty', 'john': 'denver'}
# names_dict = {
#     'jack': 'bronson',
#     'jill': 'mcarty',
#     'joe': 'denver'
# }

# del names_dict['joe']

# print(names_dict)
# Prints: {'jack': 'bronson', 'jill': 'mcarty'}



def count_enemies(enemy_names):
    res={}

    for name in enemy_names:
        if name  in res:
            res[name]+=1
        else:
            res[name]=1 
    return res           

def get_most_common_enemy(enemies_dict):
    if enemies_dict:
        key,val=next(iter(enemies_dict.items()))

        for enmy in enemies_dict:
            if enemies_dict[enmy]>val:
                val=enemies_dict[enmy]
                key=enmy


        firstdic={key:val}
        return firstdic        
    else:
        return None

enmy_names=["ziad","mostafa","gomana","mostafa","mostafa","ziad","ziad","mostafa","gomana","mostafa","mostafa","ziad"]

mydict=count_enemies(enmy_names)
res=get_most_common_enemy(mydict)
print(mydict)
print(res)
