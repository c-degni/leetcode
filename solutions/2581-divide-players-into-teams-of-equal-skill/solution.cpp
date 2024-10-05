class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        std::sort(skill.begin(), skill.end());
        long long chemistry = skill[0] * skill[skill.size() - 1];
        int totalSkill = skill[0] + skill[skill.size() - 1];

        for(int i = 1; i <= skill.size() / 2 - 1; i++)
        {
            if(skill[skill.size() - 1 - i] + skill[i] != totalSkill)
            {
                return -1;
            }
            chemistry += skill[skill.size() - 1 - i] * skill[i];
        }
        
        return chemistry;
    }
};
