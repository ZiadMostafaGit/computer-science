



def scoreparenthe(test):
    stack=[]
    score=0
    for i in test:
        if i=='(':
            stack.append(score)
            score=0
        else:
            score=stack.pop()+max(score*2,1)
    return score           




          
test1="()((())())"
test2="(()(()))"
test3="()()"
test4="(())"
test5="()"
res=scoreparenthe(test1)
print(res)

