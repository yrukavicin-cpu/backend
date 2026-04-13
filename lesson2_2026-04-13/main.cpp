#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ProjectItem {
public:
    explicit ProjectItem(std::string title) : title_(std::move(title)) {}
    virtual ~ProjectItem() = default;

    virtual void showInfo() const {
        std::cout << "Project item: " << title_ << '\n';
    }

protected:
    std::string title_;
};

class SourceModule : public ProjectItem {
public:
    SourceModule(std::string title, int linesOfCode)
        : ProjectItem(std::move(title)), linesOfCode_(linesOfCode) {}

    void showInfo() const override {
        std::cout << "Source module: " << title_
                  << ", lines of code = " << linesOfCode_ << '\n';
    }

private:
    int linesOfCode_;
};

class ReportDocument : public ProjectItem {
public:
    ReportDocument(std::string title, int pages)
        : ProjectItem(std::move(title)), pages_(pages) {}

    void showInfo() const override {
        std::cout << "Report document: " << title_
                  << ", pages = " << pages_ << '\n';
    }

private:
    int pages_;
};

void printItemByPointer(const ProjectItem* item) {
    item->showInfo();
}

class ProjectViewer {
public:
    void inspect(const ProjectItem& item) const {
        std::cout << "Viewer inspects: ";
        item.showInfo();
    }
};

int main() {
    std::cout << "Example 1: two classes, virtual call through pointer\n";
    ProjectItem* firstExample = new SourceModule("Authorization", 420);
    firstExample->showInfo();
    delete firstExample;

    std::cout << "\nExample 2: three classes, pointer to base class in function\n";
    std::vector<std::unique_ptr<ProjectItem>> items;
    items.push_back(std::make_unique<ProjectItem>("Base section"));
    items.push_back(std::make_unique<SourceModule>("Payment service", 680));
    items.push_back(std::make_unique<ReportDocument>("Course report", 24));

    for (const auto& item : items) {
        printItemByPointer(item.get());
    }

    std::cout << "\nExample 3: three classes, reference to base class in method\n";
    ProjectViewer viewer;
    SourceModule module("Notifications", 310);
    ReportDocument report("Testing protocol", 12);

    viewer.inspect(module);
    viewer.inspect(report);

    return 0;
}
